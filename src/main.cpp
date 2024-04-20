#include "invertedindex.h"
#include "converterjson.h"
#include "searchserver.h"

//#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char**argv)
{
    ConverterJSON convert;
    InvertedIndex ii;
    SearchServer ss(ii);

    ss.search(convert.GetTextDocuments());

    std::vector<std::string> requests = convert.GetRequests();

    std::vector<std::vector<std::pair<int, float>>> answers = ss.getAnswers();
    convert.putAnswers(answers);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
