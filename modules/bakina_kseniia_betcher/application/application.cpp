// Copyright 2022 Korobeinikov Alexandr

#include <string>
#include <iostream>

#include "../include/batcher_app.h"

int main(int argc, const char** argv) {
    BatcherApp app;
    std::string result = app(argc, argv);
    std::cout << result << std::endl;
    return 0;
}
