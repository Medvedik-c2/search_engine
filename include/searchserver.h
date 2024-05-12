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
    InvertedIndex _index;
    ConverterJSON convert;
    int max = 0;
public:
    SearchServer(InvertedIndex& idx);
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string> queriesInput);
    std::vector<std::string> tokenizeQuery(std::string request);
    std::vector<std::vector<std::pair<int, float> > > getAnswers() const;

    void setAnswers(const std::vector<std::vector<RelativeIndex>> &results);

    void calculateRelevance(std::vector<RelativeIndex> &relativeIndex);
    void showRelativeVector(auto req, std::vector<RelativeIndex> &relativeIndex);
};



#endif // SEARCHSERVER_H
