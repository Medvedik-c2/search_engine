#include "InvertedIndex.h"
#include "ConverterJSON.h"
#include "SearchServer.h"


int main()
{
    ConverterJSON convert;
    InvertedIndex ii;
    ii.updateDocumentBase(convert.GetTextDocuments());
    SearchServer ss(ii);
    ss.search(convert.GetRequests());

    std::vector<std::vector<std::pair<int, float>>> answers = ss.getAnswers();
    convert.putAnswers(answers);

}
