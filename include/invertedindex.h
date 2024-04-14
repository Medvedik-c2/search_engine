#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <vector>
#include <string>
#include <unordered_map>
#include <mutex>

struct Entry
{
    size_t docId, count=0;
    // Данный оператор необходим для проведения тестовых сценариев
    bool operator ==(const Entry& other) const {
        return (docId == other.docId &&
                count == other.count);
    }
};

class InvertedIndex
{
    std::vector<std::string> docs;
    std::unordered_map<std::string, std::vector<Entry>> freqDictionary;

    void processFreqDictionary (std::string& doc, size_t& id, std::mutex &mtx);
public:
    InvertedIndex() = default;
    ~InvertedIndex() = default;
    void updateDocumentBase (const std::vector<std::string>& _docs);
    void setFreqDictionary ();
    void showFreqDictionary ();
    std::vector<Entry> GetWordCount(const std::string& request);

};

#endif // INVERTEDINDEX_H
