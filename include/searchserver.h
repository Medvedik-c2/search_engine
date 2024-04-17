#ifndef SEARCHSERVER_H
#define SEARCHSERVER_H

#include "invertedindex.h"

struct RelativeIndex{
    size_t doc_id;
    float rank;
    bool operator ==(const RelativeIndex& other) const {
        return (doc_id == other.doc_id && rank == other.rank);
    }
};

class SearchServer
{
    std::vector<std::vector<std::pair<int,float>>> answers;
    std::vector<int> sortedQueryNumbers;

    int max = 0;
public:
    SearchServer(InvertedIndex& idx);
    std::vector<std::pair<int, std::vector<RelativeIndex>>> search(const std::vector<std::string>& queriesInput);
    std::vector<std::string> tokenizeQuery(std::string request);
    std::vector<std::vector<std::pair<int, float> > > getAnswers() const;

    void sortVector(std::vector<std::pair<int, std::vector<RelativeIndex> > > &resultRelative);
    std::vector<int> getSortedQueryNumbers() const;

private:
    InvertedIndex _index;

};



#endif // SEARCHSERVER_H
