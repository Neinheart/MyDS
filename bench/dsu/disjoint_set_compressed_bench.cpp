#include "dsu/disjoint_set_compressed.h"
#include "registry.h"
#include <chrono>
#include <iostream>
#include <random>

using namespace dsu_compressed;

static void run_dsu_disjoint_set_compressed_bench() {
    constexpr int N = 1'000'000;
    DisjointSet dsu(N);

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, N);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i)
        dsu.union_sets(dist(rng), dist(rng));
    for (int i = 0; i < N; ++i)
        dsu.find(dist(rng));

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "[bench] compressed DSU union+find on " << N << " elements: " << elapsed.count() << " seconds\n";
}

REGISTER_BENCH_TEST(dsu_disjoint_set_compressed, run_dsu_disjoint_set_compressed_bench)
