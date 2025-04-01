#include "dsu/disjoint_set_naive.h"

namespace dsu_naive {

    DisjointSet::DisjointSet(int n) : parent_(n + 1) {
        for (int i = 0; i <= n; ++i) parent_[i] = i;
    }

    int DisjointSet::find(int x) {
        if (x == parent_[x]) return x;
        return find(parent_[x]);
    }

    void DisjointSet::union_sets(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        parent_[root_b] = root_a;
    }

}
