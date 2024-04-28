#ifndef SEARCHSERVER_H
#define SEARCHSERVER_H

#include "invertedindex.h"
#include "converterjson.h"

struct RelativeIndex{
    size_t docId;
    float rank;
    bool operator ==(const RelativeIndex& other) const {
        return (docId == other.docId && rank == other.rank);
    }
};

class SearchServer
{
    std::vector<std::vector<std::pair<int,float>>> answers;

    int max = 0;
public:
    SearchServer(InvertedIndex& idx);
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string> queriesInput);
    std::vector<std::string> tokenizeQuery(std::string request);
    std::vector<std::vector<std::pair<int, float> > > getAnswers() const;

    void showVector(auto vec) const;
    void showMultimap(auto mm) const;
    void showVV(auto vv) const;
    void showMap(auto m) const;
    void setAnswers(const std::vector<std::vector<RelativeIndex>> &results);

    void showVVP(auto vv) const;
    void calculateRelevance(std::vector<RelativeIndex> &relativeIndex);
    void showRelativeVector(auto req, std::vector<RelativeIndex> &relativeIndex);
private:
    InvertedIndex _index;
    ConverterJSON convert;
    std::vector<int> sumWordsInFiles;

};



#endif // SEARCHSERVER_H
