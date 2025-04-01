#pragma once
#include <vector>

namespace dsu_naive {

    class DisjointSet {
    public:
        explicit DisjointSet(int n);
        void union_sets(int a, int b);
        int find(int x);
    private:
        std::vector<int> parent_;
    };

}
