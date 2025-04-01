#pragma once

#include <vector>

namespace dsu_compressed {

    class DisjointSet {
    public:
        explicit DisjointSet(int n);

        int find(int x);

        void union_sets(int a, int b);

    private:
        std::vector<int> parent_;
    };

} // namespace dsu_compressed