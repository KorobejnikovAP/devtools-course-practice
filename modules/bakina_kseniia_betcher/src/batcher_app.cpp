// Copyright 2022 Korobeinikov Alexandr

#include <string>
#include <stdexcept>
#include <vector>

#include "../include/batcher_app.h"
#include "../include/backina_kseniia_betcher.h"

BatcherApp::BatcherApp() {}

std::string BatcherApp::operator() (int argc, const char** argv) {
    if (argc != 2 && argc != 3) {
        return this->argument_error();
    }

    std::string arg1 = std::string(argv[1]);
    if (arg1 == "--help" || arg1 == "-h") {
        return this->help();
    }

    try {
        EvenOddBetcher merge;
        std::vector<int> v1;
        std::vector<int> v2;
        std::string arg2 = std::string(argv[2]);

        size_t k = 0;
        std::string tmp = "";
        while (k < arg1.length()) {
            if (arg1[k] == ',') {
                v1.push_back(std::stoi(tmp));
                tmp = "";
                k++;
                continue;
            }
            tmp += arg1[k];
            k++;
            if (k == arg1.length()) {
                v1.push_back(std::stoi(tmp));
                break;
            }
        }

        k = 0;
        tmp = "";
        while (k < arg2.length()) {
            if (arg2[k] == ',') {
                v2.push_back(std::stoi(tmp));
                tmp = "";
                k++;
                continue;
            }
            tmp += arg2[k];
            k++;
            if (k == arg2.length()) {
                v2.push_back(std::stoi(tmp));
                break;
            }
        }

        std::vector<int> result = merge.EvenOddBetcher_merge(v1, v2);
        std::string str_result = "";
        for (int i : result) {
            str_result += std::to_string(i) + ",";
        }
        str_result.pop_back();
        return str_result;
    }
    catch (std::invalid_argument& e) {
        return this->merge_error(e);
    }
}

std::string BatcherApp::help() {
    std::string help = std::string("")
        + "Welcome to merge Batcherq app!\n"
        + "Please enter two vectors to merge\n"
        + "Generally you can type something like 1,3,4 2,5,6 \n";
    return help;
}

std::string BatcherApp::argument_error() {
    std::string error = std::string("")
        + "Invalid argument amount, try --help or -h command";
    return error;
}

std::string BatcherApp::merge_error(const std::invalid_argument& e) {
    std::string error = std::string("")
        + "Merge error occured!\n"
        + e.what();
    return error;
}
