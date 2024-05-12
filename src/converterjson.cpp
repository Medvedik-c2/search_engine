#include "converterjson.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>


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
        inconfig.close();

        // Проверка наличия поля "files" и его типа
        if (!config.contains("files") || !config["files"].is_array()) {
            throw std::runtime_error("Missing or invalid 'files' field in config.json");
        }

        for (const auto& pathfile : config["files"]) {
            // Проверка корректности заполнения поля "files"
            if (!pathfile.is_string()) {
                throw std::runtime_error("Invalid 'files' entry in config.json");
            }
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
        inconfig.close();

        if (config["config"].find("max_responses") == config["config"].end()) {
            throw std::runtime_error("max_responses not found in config file");
        }
        if (config["config"]["max_responses"] < 1 || !config["config"]["max_responses"].is_number()) {
            throw std::runtime_error("incorrect 'max_responses' in config file");
        }
        responsesLimit = config["config"]["max_responses"];
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
        // Проверяем наличие поля "requests" в файле
        if (!r.contains("requests") || !r["requests"].is_array()) {
            throw std::runtime_error("Missing or invalid 'requests' field in requests.json");
        }


        for (auto& request : r["requests"]) {
            // Проверяем корректность заполнения поля "requests"
            if (!request.is_string()) {
                throw std::runtime_error("Invalid 'requests' entry in requests.json");
            }
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
                std::stringstream ss;
                ss << std::fixed << std::setprecision(3) << pair.second;
                std::string rank = ss.str();

                relevance.push_back("docID: " + std::to_string(pair.first) + ", rank: " + rank);
            }
            request["relevance"] = relevance;
        } else if (!answer.empty()) {
            request["result"] = "true";
            request["docid"] = answer[0].first;
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
