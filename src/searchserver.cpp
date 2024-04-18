#include "searchserver.h"
#include "converterjson.h"
#include <sstream>
#include <map>
//#include <algorithm>
//#include <iostream>

std::vector<std::vector<std::pair<int, float>>> SearchServer::getAnswers() const
{
    return answers;
}

SearchServer::SearchServer(InvertedIndex &idx) : _index(idx){}

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> &queriesInput)
{
    ConverterJSON convert;
    std::vector<std::vector<RelativeIndex>> resultRelative;
    _index.updateDocumentBase(queriesInput);

    std::vector<std::string> requests = convert.GetRequests();
    //создание списка уникальных слов в запросах и сортировка
    //по возрастанию упоминаний
    std::multimap<int, std::string> countRequest;
    for (auto& req : requests) {
        std::vector<std::string> tokenizeRequest = tokenizeQuery(req);
        std::vector<RelativeIndex> relativeIndex;
        for (auto &token : tokenizeRequest) {
            std::vector<std::pair<int, float>> answer;
            int count = 0;
            bool unique = true;
            for (auto& it : _index.GetWordCount(token)){
                count += it.count;
                relativeIndex.push_back({it.docId,(float)it.count});
                answer.push_back(std::pair<int, float>(static_cast<int>(it.docId), (float)it.count));
            }
            resultRelative.push_back(relativeIndex);
            answers.push_back(answer);

            for (const auto& pair : countRequest) {
                if (pair.second == token) unique = false;
            }
            if (unique)
                countRequest.insert(std::pair<int, std::string>(count, token));
        }
    }
    //достать из списка частот и посчитать релевантность
    std::unordered_map<std::string, std::vector<Entry>> freqDictionaryAnswer;
    for (auto it = countRequest.begin(); it != countRequest.end(); ++it) {
        if (it == countRequest.end()) break;
        freqDictionaryAnswer.insert(std::pair<std::string, std::vector<Entry>>(it->second, _index.GetWordCount(it->second)));
    }
    std::map<size_t, int> absoluteRelevance;

    for(auto& word : freqDictionaryAnswer){
        for(auto& entry : word.second){
            absoluteRelevance[entry.docId] += entry.count;
            if (absoluteRelevance[entry.docId] > max) max = absoluteRelevance[entry.docId];
        }
    }
    for(auto& request : answers){
        for(auto& doc : request){
            doc.second = doc.second / max;
        }
    }
    for(auto& request : resultRelative){
        for(auto& doc : request){
            doc.rank = doc.rank / max;
        }
    }

    return resultRelative;
}

//разбить строку запроса на слова
std::vector<std::string> SearchServer::tokenizeQuery(std::string request) {
    std::vector<std::string> result;
    std::stringstream ss(request);
    std::string word;
    while(ss >> word) {
        result.push_back(word);
    }
    return result;
}
