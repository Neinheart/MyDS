#include "dsu/disjoint_set_naive.h"
#include "registry.h"
#include "doctest.h"
#include <format>
#include <iostream>

using namespace dsu_naive;

static void run_dsu_disjoint_set_naive_test() {
    doctest::Context ctx;
    ctx.setOption("no-breaks", true);
    ctx.setOption("test-suite", "[dsu_naive]");
    ctx.run();
}

REGISTER_FUNC_TEST(dsu_disjoint_set_naive, run_dsu_disjoint_set_naive_test)

TEST_SUITE("[dsu_naive]") {
    TEST_CASE("basic union-find") {
        DisjointSet dsu(5);
        dsu.union_sets(1, 2);
        dsu.union_sets(2, 3);
        CHECK(dsu.find(1) == dsu.find(3));
        std::cout << std::format("[naive test] find(3) = {}\n", dsu.find(3));
    }

    TEST_CASE("edge cases") {
        SUBCASE("singleton set") {
            DisjointSet dsu(1);
            CHECK(dsu.find(1) == 1);
        }

        SUBCASE("duplicate unions") {
            DisjointSet dsu(3);
            dsu.union_sets(1, 2);
            dsu.union_sets(1, 2);
            CHECK(dsu.find(1) == dsu.find(2));
        }

        SUBCASE("fully merged set") {
            DisjointSet dsu(100);
            for (int i = 1; i < 100; ++i)
                dsu.union_sets(i, i + 1);
            for (int i = 1; i <= 100; ++i)
                CHECK(dsu.find(i) == dsu.find(1));
        }
    }
}