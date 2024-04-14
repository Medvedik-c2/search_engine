#include "invertedindex.h"
#include "converterjson.h"

//#include <iostream>
#include "gtest/gtest.h"

TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char**argv)
{

    ConverterJSON convert;
    InvertedIndex ii;

    ii.updateDocumentBase(convert.GetTextDocuments());

    std::cout << convert.GetResponsesLimit() << std::endl;
    for(auto& req : convert.GetRequests()){
        ii.GetWordCount(req);
    }


    //ii.showFreqDictionary();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
