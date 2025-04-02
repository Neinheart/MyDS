#include "dsu/disjoint_set_rank.h"
#include "registry.h"
#include "doctest.h"

using namespace dsu_rank;

static void run_dsu_disjoint_set_rank_test() {
    doctest::Context ctx;
    ctx.setOption("no-breaks", true);
    ctx.setOption("test-suite", "[dsu_rank]");
    ctx.run();
}

REGISTER_FUNC_TEST(dsu_disjoint_set_rank, run_dsu_disjoint_set_rank_test)

TEST_SUITE("[dsu_rank]") {
    TEST_CASE("basic union-find") {
        DisjointSet dsu(6);
        dsu.union_sets(1, 2);
        dsu.union_sets(2, 3);
        CHECK(dsu.find(1) == dsu.find(3));
        CHECK(dsu.find(4) != dsu.find(1));
    }

    TEST_CASE("edge cases") {
        SUBCASE("singleton") {
            DisjointSet dsu(1);
            CHECK(dsu.find(1) == 1);
        }

        SUBCASE("fully connected") {
            DisjointSet dsu(100);
            for (int i = 1; i < 100; ++i) dsu.union_sets(i, i + 1);
            for (int i = 1; i <= 100; ++i)
                CHECK(dsu.find(i) == dsu.find(1));
        }
    }

    TEST_CASE("rank corruption detection") {
        DisjointSet dsu(6);

        // make two trees with equal rank (1-2, 3-4)
        dsu.union_sets(1, 2);
        dsu.union_sets(3, 4);

        // now both 1 and 3 should be roots of depth-1 trees
        // next: 1 and 3 will be merged, ranks equal, so 1 becomes root and rank[1] += 1
        dsu.union_sets(1, 3);

        // now: union(5, 1) will use rank to decide merge direction
        dsu.union_sets(5, 1);

        // if rank[1] is broken by a bad find() call before this step,
        // 5 may become the root, which is incorrect
        CHECK(dsu.find(5) == dsu.find(2));
    }

    TEST_CASE("union-by-rank correctness check") {
        DisjointSet dsu(10);

        // manully make 1~5 each connected to 0 individually, increasing rank[0]
        for (int i = 1; i <= 5; ++i)
            dsu.union_sets(0, i);

        // now do union_sets(6, 0) — it should merge 6 into 0
        dsu.union_sets(6, 0);

        // then do union_sets(7, 6) — now 7 should also go under 0
        dsu.union_sets(7, 6);

        // find(7) must be equal to find(0)
        CHECK(dsu.find(7) == dsu.find(0));
    }

}
