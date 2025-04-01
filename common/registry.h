#pragma once
#include <string>
#include <unordered_map>
#include <functional>



using TestFunc = std::function<void()>;

inline std::unordered_map<std::string, TestFunc>& func_test_registry() {
    static std::unordered_map<std::string, TestFunc> inst;
    return inst;
}

inline std::unordered_map<std::string, TestFunc>& bench_test_registry() {
    static std::unordered_map<std::string, TestFunc> inst;
    return inst;
}

inline void register_func_test(const std::string& name, TestFunc fn) {
    func_test_registry()[name] = fn;
}

inline void register_bench_test(const std::string& name, TestFunc fn) {
    bench_test_registry()[name] = fn;
}

#define REGISTER_FUNC_TEST(name, fn) \
namespace { \
struct Reg_##name { Reg_##name() { register_func_test(#name, fn); }}; \
static Reg_##name _reg_##name; \
}

#define REGISTER_BENCH_TEST(name, fn) \
namespace { \
struct RegBench_##name { RegBench_##name() { register_bench_test(#name, fn); }}; \
static RegBench_##name _reg_bench_##name; \
}
