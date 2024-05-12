#include "InvertedIndex.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <algorithm>




void InvertedIndex::processFreqDictionary(std::string doc, size_t id, std::mutex& mtx)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::istringstream iss(doc);
    std::string word;

    while (iss >> word) {
        auto it = freqDictionary.find(word);
        if(it != freqDictionary.end()) {
            auto& entryList = it->second;
            auto foundIt = std::find_if(entryList.begin(), entryList.end(), [&](const Entry& entry) {
                return entry.docId == id;
            });
            if(foundIt != entryList.end()){
                foundIt->count++;
                //std::cout << word << " " << foundIt->docId << ":" << foundIt->count << std::endl;
            }
            else {
                entryList.push_back({id, 1});
            }
        }
        else {
            freqDictionary.try_emplace(word, std::vector<Entry>{{id, 1}});
        }
    }
}


void InvertedIndex::updateDocumentBase(const std::vector<std::string>& inputDocs)
{
    if (inputDocs.empty()) std::cerr << "Document is empty!" << std::endl;
    else {
        docs.clear();
        docs.reserve(inputDocs.size());
        for(const auto& doc : inputDocs) {
            docs.push_back(doc);
        }
    }
    setFreqDictionary();
    //showDictionary();
}

void InvertedIndex::setFreqDictionary()
{
    std::vector<std::thread> threads;
    std::mutex mtx;
    size_t id = 0;
    for(auto& doc : docs) {        
        threads.emplace_back(&InvertedIndex::processFreqDictionary, this, doc, id, std::ref(mtx));
        id++;
    }
    for (auto& thread : threads) {
        thread.join();
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


// for debug
/*
void InvertedIndex::showDictionary()
{
    for(auto& s : freqDictionary){
        std::cout << s.first << "\t";
        for(auto& e : s.second){
            std::cout << e.docId << ":" << e.count << " ";
        }
        std::cout << std::endl;
    }
}
void InvertedIndex::showVector(auto vec) const {
    for(auto& it : vec){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}
*/
