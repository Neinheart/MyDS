#pragma once

#include <vector>

namespace dsu_rank {

    class DisjointSet {
    public:
        explicit DisjointSet(int n);
        int find(int x);
        void union_sets(int a, int b);

    private:
        std::vector<int> parent_;
        std::vector<int> rank_; // heuristic optimization based on rank
    };

}
