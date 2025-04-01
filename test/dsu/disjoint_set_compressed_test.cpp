#include "dsu/disjoint_set_compressed.h"
#include "registry.h"
#include "doctest.h"
#include <format>
#include <iostream>

using namespace dsu_compressed;

static void run_dsu_disjoint_set_compressed_test() {
    doctest::Context ctx;
    ctx.setOption("no-breaks", true);
    ctx.setOption("test-suite", "[dsu_compressed]");
    ctx.run();
}

REGISTER_FUNC_TEST(dsu_disjoint_set_compressed, run_dsu_disjoint_set_compressed_test)

TEST_SUITE("[dsu_compressed]") {
    TEST_CASE("basic union-find") {
        DisjointSet dsu(6);
        dsu.union_sets(1, 2);
        dsu.union_sets(2, 3);
        CHECK(dsu.find(1) == dsu.find(3));
        CHECK(dsu.find(4) != dsu.find(1));
        std::cout << std::format("[compressed test] find(3) = {}\n", dsu.find(3));
    }
}