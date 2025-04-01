#include "registry.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./main <mode: func|bench|all> <test_path>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string key = argv[2];

    if (mode == "func" || mode == "all") {
        auto it = func_test_registry().find(key);
        if (it != func_test_registry().end()) {
            std::cout << "[Run Functional Test] " << key << "\n";
            it->second();
        } else {
            std::cout << "[Functional Test Not Found] " << key << "\n";
        }
    }

    if (mode == "bench" || mode == "all") {
        auto it = bench_test_registry().find(key);
        if (it != bench_test_registry().end()) {
            std::cout << "[Run Benchmark Test] " << key << "\n";
            it->second();
        } else {
            std::cout << "[Benchmark Test Not Found] " << key << "\n";
        }
    }

    return 0;
}