#include "converterjson.h"
#include "gtest/gtest.h"


TEST(ConverterJSONTest, GetTextDocuments)
{
    ConverterJSON converter;

    // Проверка, что метод возвращает непустой вектор строк
    EXPECT_FALSE(converter.GetTextDocuments().empty());
}

TEST(ConverterJSONTest, GetResponsesLimit)
{
    ConverterJSON converter;

    // Проверка, что метод возвращает ненулевое значение
    EXPECT_NE(converter.GetResponsesLimit(), 0);
}

TEST(ConverterJSONTest, GetRequests)
{
    ConverterJSON converter;

    // Проверка, что метод возвращает непустой вектор строк
    EXPECT_FALSE(converter.GetRequests().empty());
}

TEST(ConverterJSONTest, putAnswers)
{
    ConverterJSON converter;

    // Создание и передача в метод пустого вектора ответов
    std::vector<std::vector<std::pair<int, float>>> answers;
    converter.putAnswers(answers);

    // TODO: добавить проверку созданного файла ответов
}

