#include "invertedindex.h"
#include "converterjson.h"
#include "searchserver.h"


int main()
{
    ConverterJSON convert;
    InvertedIndex ii;
    SearchServer ss(ii);

    ii.updateDocumentBase(convert.GetTextDocuments());
    ss.search(convert.GetRequests());

    std::vector<std::vector<std::pair<int, float>>> answers = ss.getAnswers();
    convert.putAnswers(answers);

}
