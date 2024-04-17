#include "converterjson.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

std::vector<std::size_t> ConverterJSON::Doc () {return doc;}

void ConverterJSON::setNumberRequests(const std::vector<int> &newSortedNumberRequests)
{
    numbersRequests = newSortedNumberRequests;
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
            doc.push_back(n++);
            std::string line;
            while (std::getline(infile, line)) {
                list.push_back(line);
            }
        }
        inconfig.close();
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
        std::cout << "limit: " << responsesLimit << std::endl;
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
    jsonAnswer["answers"] = nlohmann::json::array();
    int i = 0;
    for (auto& answer : answers) {
        nlohmann::json request;
        std::string requestKey = "request_00" + std::to_string(numbersRequests[i]);
        request[requestKey] = nlohmann::json::array();
        if (answer.empty()) request["result"] = "false";
        else {
            request["result"] = "true";
            nlohmann::json relevance;
            for(const auto& pair : answer) {
                relevance.push_back({{"docId", pair.first}, {"rank", pair.second}});
            }
            request[requestKey].push_back(relevance);
        }
        jsonAnswer["answers"].push_back(request);
        i++;
    }
    try {
        std::ofstream outAnswer("resources/answer.json");
        if (!outAnswer.is_open()) {
            throw std::runtime_error("Failed to open answers.json for writing");
        }
        outAnswer << std::setw(4) << jsonAnswer << std::endl;
        outAnswer.close();
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::vector<std::vector<std::pair<int, float>>> ConverterJSON::processAnswers(){
    std::vector<std::vector<std::pair<int, float>>> ans;
    return ans;
};
