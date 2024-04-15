#ifndef CONVERTERJSON_H
#define CONVERTERJSON_H

#include <vector>
#include <string>

class ConverterJSON {

    std::vector<std::size_t> doc;
public:
    ConverterJSON() = default;

    std::vector<std::string> GetTextDocuments();

    int GetResponsesLimit();

    std::vector<std::string> GetRequests();

    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);

    std::vector<std::vector<std::pair<int, float>>> processAnswers();

    std::vector<std::size_t> Doc();
};


#endif // CONVERTERJSON_H
