#include "dsu/disjoint_set_rank.h"

namespace dsu_rank {
    DisjointSet::DisjointSet(int n) : parent_(n + 1), rank_(n + 1, 0) {
        for (int i = 0; i <= n; ++i)
            parent_[i] = i;
    }

    int DisjointSet::find(int x) {
        if (x == parent_[x]) {
            return x;
        }
        parent_[x] = find(parent_[x]);
        return parent_[x];
    }

    void DisjointSet::union_sets(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (rank_[root_a] < rank_[root_b]) {
            parent_[root_a] = root_b;
        } else if (rank_[root_a] > rank_[root_b]) {
            parent_[root_b] = root_a;
        } else {
            rank_[root_a]++;
            parent_[root_b] = root_a;
        }
    }
} // namespace dsu_rank
