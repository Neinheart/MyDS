#include "dsu/disjoint_set_compressed.h"

namespace dsu_compressed {

    DisjointSet::DisjointSet(int n) : parent_(n + 1) {
        for (int i = 0; i <= n; ++i) parent_[i] = i;
    }

    int DisjointSet::find(int x) {

    }


    void DisjointSet::union_sets(int a, int b) {
    }

}
