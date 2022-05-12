// Copyright 2022 Korobeinikov Alexandr

#ifndef MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BATCHER_APP_H_
#define MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BATCHER_APP_H_

#include <string>
#include <stdexcept>
#include <vector>

class BatcherApp {
 public:
    BatcherApp();
    std::string operator()(int argc, const char** argv);

 private:
    std::string help();
    std::string argument_error();
    std::string merge_error(const std::invalid_argument& e);
};

#endif  // MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BATCHER_APP_H_
