#include "searchserver.h"
#include "converterjson.h"
#include <sstream>
#include <algorithm>
//#include <iostream>
#include <map>

std::vector<std::vector<std::pair<int, float>>> SearchServer::getAnswers() const
{
    return answers;
}

void SearchServer::setAnswers(const std::vector<std::vector<RelativeIndex>> &results)
{
    std::vector<std::vector<std::pair<int, float>>> newAnswers;
    for(auto& result : results){
        std::vector<std::pair<int, float>> newAnswer;
        for(auto& it : result){
            int id = it.docId;
            float rank = it.rank;
            newAnswer.push_back(std::make_pair(id, rank));
        }
        newAnswers.push_back(newAnswer);
    }
    answers = newAnswers;
}

SearchServer::SearchServer(InvertedIndex &idx) : _index(idx){}

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> queriesInput)
{
    std::vector<std::vector<RelativeIndex>> resultRelative;

    std::multimap<int, std::string> countRequest;

    //работа с каждым запросом
    for (const auto &req : queriesInput) {
        std::vector<RelativeIndex> relativeIndex;        
        //работа с каждым словом запроса
        for (auto &token : tokenizeQuery(req)) {
            int count = 0;
            bool unique = true;
            //работаем с каждым файлом в котором есть упоминания токена
            for (auto& it : _index.GetWordCount(token)){
                count += it.count;
                size_t id = it.docId;
                auto iter = std::find_if(relativeIndex.begin(), relativeIndex.end(), [id](const RelativeIndex& ri) {
                    return ri.docId == id;
                });
                if (iter != relativeIndex.end()) {
                    iter->rank += it.count;
                } else {
                    relativeIndex.push_back({it.docId,(float)it.count});
                }                
            }
            //std::cout << token << std::endl;
            //showRelativeVector(req ,relativeIndex);
            for (const auto& pair : countRequest) {
                if (pair.second == token) unique = false;
            }
            if (unique)
                countRequest.insert(std::pair<int, std::string>(count, token));
        }

        calculateRelevance(relativeIndex);

        //отсекаем все лишнее
        int maxResponces = convert.GetResponsesLimit();
        while(relativeIndex.size() > maxResponces){
            relativeIndex.pop_back();
        }
        resultRelative.push_back(relativeIndex);
    }
    setAnswers(resultRelative);
    //_index.showDictionary();
    return resultRelative;
}


void SearchServer::calculateRelevance(std::vector<RelativeIndex> &relativeIndex){
    //поиск максимума для запроса
    max = 0;
    for(auto& it : relativeIndex){
        if(it.rank > max) max = it.rank;
    }
    //из абсолютной делаем относительную релевантность
    for(auto& it : relativeIndex){
        //int id = it.docId;
        //std::cout << "!!! id:" << id << " max: " << max << " rank absolute: " << it.rank << std::endl;
        it.rank = it.rank / max;
    }

    //сортируем файлы по релевантности
    std::sort(relativeIndex.begin(), relativeIndex.end(), [](const RelativeIndex& a, const RelativeIndex& b) {
        if (a.rank == b.rank) {
            return a.docId < b.docId;
        }
        return a.rank > b.rank;
    });
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


/*void SearchServer::showVVP (auto vv) const {
    std::cout << "ANSWERS: \n\n";
    for(auto& v: vv){
        for(auto& it : v){
            std::cout << it.first << " ::: " << it.second << std::endl;
        }
        std::cout << "======" << std::endl;
    }
}

void SearchServer::showVector(auto vec) const {
    for(auto& it : vec){
        std::cout << it << std::endl;
    }
}

void SearchServer::showMultimap(auto mm) const {
    for(auto& it : mm){
        std::cout << it.first << " - " << it.second << std::endl;
    }
}
void SearchServer::showMap(auto m) const {
    for(auto& it : m){
        std::cout << it.first << " \t ";
        for(auto& t : it.second) {
            std::cout << t.docId << ": " << t.count << "\t";
        }
        std::cout << std::endl;
    }
}

void SearchServer::showVV (auto vv) const {
    for(auto& v: vv){
        for(auto& it : v){
            std::cout << it.docId << " ::: " << it.rank << std::endl;
        }
        std::cout << "======" << std::endl;
    }
}

void SearchServer::showRelativeVector(auto req, std::vector<RelativeIndex> &relativeIndex){
    //std::cout << req;
    for(auto& it : relativeIndex){
        std::cout << "  "<< it.docId << ":" << it.rank;
    }
    std::cout << "\n";
}
*/
