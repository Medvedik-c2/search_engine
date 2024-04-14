#include "invertedindex.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <algorithm>



void InvertedIndex::processFreqDictionary(std::string &doc, size_t& id, std::mutex& mtx)
{
    std::istringstream iss(doc);
    std::string word;

    mtx.lock();
    while (std::getline(iss, word, ' ')) {

        auto it = freqDictionary.find(word);
        if(it != freqDictionary.end()) {

            auto& entryList = it->second;
            auto foundIt = std::find_if(entryList.begin(), entryList.end(), [&](const Entry& entry) {
                return entry.docId == id;
            });
            if(foundIt != entryList.end()){
                foundIt->count++;
            }
            else {
                entryList.push_back({id, 1});
            }
        }
        else {
            freqDictionary[word] = {{id, 1}};
        }

    }
    mtx.unlock();
}

void InvertedIndex::updateDocumentBase(const std::vector<std::string>& inputDocs)
{
    if (inputDocs.empty()) std::cerr << "Document is empty!" << std::endl;
    else {
        docs = inputDocs;
    }
    setFreqDictionary();
}

void InvertedIndex::setFreqDictionary()
{
    std::vector<std::thread> threads;
    std::mutex mtx;
    size_t id = 0;
    for(auto& doc : docs) {        
        threads.emplace_back(&InvertedIndex::processFreqDictionary,this, std::ref(doc), std::ref(id), std::ref(mtx));
        id++;
    }
    for (auto& thread : threads) {
        thread.join();
    }
}

void InvertedIndex::showFreqDictionary()
{
    for(auto& word : freqDictionary){
        std::cout << word.first << " = ";
        for (auto& file : word.second) {
            std::cout << file.docId << " : " << file.count << "   ";
        }
        std::cout << std::endl;
    }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& request)
{
    std::vector<Entry> result;
    auto it = freqDictionary.find(request);
    if(it != freqDictionary.end()) {
        for(auto& entry : it->second){
            result.push_back(entry);
        }
    }
    return result;
}
