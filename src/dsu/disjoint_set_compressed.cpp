#include "dsu/disjoint_set_compressed.h"

namespace dsu_compressed {

    DisjointSet::DisjointSet(int n) : parent_(n + 1) {
        for (int i = 0; i <= n; ++i) parent_[i] = i;
    }

    int DisjointSet::find(int x) {
        if (x != parent_[x])
            parent_[x] = find(parent_[x]);
        return parent_[x];
    }

    void DisjointSet::union_sets(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        parent_[root_b] = root_a;
    }

}