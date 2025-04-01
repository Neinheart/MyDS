#include "dsu/disjoint_set_compressed.h"
#include "registry.h"
#include <chrono>
#include <format>
#include <iostream>

using namespace dsu_compressed;

static void run_dsu_disjoint_set_compressed_bench() {
    const int N = 1'000'000;
    DisjointSet dsu(N);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < N; ++i) dsu.union_sets(i, i + 1);
    for (int i = 1; i <= N; ++i) dsu.find(i);
    auto end = std::chrono::high_resolution_clock::now();

    double time = std::chrono::duration<double>(end - start).count();
    std::cout << std::format("[bench] compressed DSU union+find on {} elements: {:.6f} seconds\n", N, time);
}

REGISTER_BENCH_TEST(dsu_disjoint_set_compressed, run_dsu_disjoint_set_compressed_bench)