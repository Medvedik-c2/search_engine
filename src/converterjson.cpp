#include "converterjson.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>


std::vector<int> ConverterJSON::getCountWords() const
{
    return countWords;
}

std::vector<std::string> ConverterJSON::GetTextDocuments()
{
    std::vector<std::string> list;
    try {
        nlohmann::json config;
        std::ifstream inconfig;
        inconfig.open("resources/config.json");
        if (!inconfig.is_open()) {
            throw std::runtime_error("Failed to open config.json");
        }
        inconfig >> config;
        size_t n = 0;
        for (auto& pathfile : config["files"]) {
            std::ifstream infile(pathfile);
            if (!infile.is_open()) {
                std::cerr << "[FAIL] " << pathfile << " is missing" << std::endl;
                continue;
            }
            std::string line;
            while (std::getline(infile, line)) {
                list.push_back(line);
            }
        }
        inconfig.close();
        //заполняем количество слов в каждом файле
        int sumWords = 0;
        for(auto it : list){
            std::stringstream ss(it);
            std::string word;
            while(ss >> word){
                sumWords++;
            }
            countWords.push_back(sumWords);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return list;
}

int ConverterJSON::GetResponsesLimit()
{
    int responsesLimit = 0;
    try {
        nlohmann::json config;
        std::ifstream inconfig("resources/config.json");
        if (!inconfig.is_open()) {
            throw std::runtime_error("Failed to open config.json");
        }
        inconfig >> config;
        if (config["config"].find("max_responses") == config["config"].end()) {
            throw std::runtime_error("max_responses not found in config file");
        }
        responsesLimit = config["config"]["max_responses"];
        //std::cout << "limit: " << responsesLimit << std::endl;
        inconfig.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
return responsesLimit;
}

std::vector<std::string> ConverterJSON::GetRequests()
{
    std::vector<std::string> requests;
    try {
        std::ifstream inRequests("resources/requests.json");
        if (!inRequests.is_open()) {
            throw std::runtime_error("Failed to open request.json");
        }
        nlohmann::json r;
        inRequests >> r;
        inRequests.close();

        for (auto& request : r["requests"]) {
            requests.push_back(request);
        }

    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return requests;
}

void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
{
    nlohmann::json jsonAnswer;
    jsonAnswer["answers"] = nlohmann::json::object();
    int i = 0;
    for (auto& answer : answers) {
        std::string requestKey = "request_" + std::to_string(i + 1);
        nlohmann::json request;
        if (answer.size() > 1) {
            request["result"] = "true";
            nlohmann::json relevance;
            for (const auto& pair : answer) {
                //округляем до 3х знаков
                std::stringstream ss;
                ss << std::fixed << std::setprecision(3) << pair.second;
                std::string rank = ss.str();

                relevance.push_back("docID: " + std::to_string(pair.first) + ", rank: " + rank);
            }
            request["relevance"] = relevance;
        } else if (!answer.empty()) {
            request["result"] = "true";
            request["docid"] = answer[0].first;
            //округляем до 3х знаков
            std::stringstream ss;
            ss << std::fixed << std::setprecision(3) << answer[0].second;
            std::string rank = ss.str();
            request["rank"] = rank;
        } else {
            request["result"] = "false";
        }
        jsonAnswer["answers"][requestKey] = request;
        i++;
    }
    try {
        std::ofstream outAnswer("resources/answer.json");
        if (!outAnswer.is_open()) {
            throw std::runtime_error("Failed to open answers.json for writing");
        }
        outAnswer << std::setw(4) << jsonAnswer << std::endl; // Установка отступов
        outAnswer.close();
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
