#include "dsu/disjoint_set_naive.h"
#include "registry.h"
#include <chrono>
#include <iostream>
#include <random>

using namespace dsu_naive;

static void run_dsu_disjoint_set_naive_bench() {
    constexpr int N = 100'000;

    DisjointSet dsu(N);

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, N);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i)
        dsu.union_sets(dist(rng), dist(rng));
    for (int i = 0; i < N; ++i)
        dsu.find(dist(rng));

    auto end = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration<double>(end - start).count();
    std::cout << std::format("[bench] naive DSU union+find on {} elements: {:.6f} seconds\n", N, time);
}

REGISTER_BENCH_TEST(dsu_disjoint_set_naive, run_dsu_disjoint_set_naive_bench)
