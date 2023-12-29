#include <iostream>
#include <vector>

public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        components = n;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            components--;
        }
    }

    int getComponents() const {
        return components;
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
    int components;
};

int minOperations(int N, const std::vector<std::pair<int, int>>& routes) {
    UnionFind uf(N);

    for (const auto& route : routes) {
        uf.unionSets(route.first, route.second);
    }

    // If there is only one connected component, all cities are already connected
    if (uf.getComponents() == 1) {
        return 0;
    }

    // Count the number of existing routes between connected cities
    int existingRoutes = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (uf.find(i) != uf.find(j)) {
                existingRoutes++;
            }
        }
    }

    // Calculate the minimum number of operations needed
    int requiredRoutes = uf.getComponents() - 1; // Number of edges to connect all components
    return (existingRoutes >= requiredRoutes) ? requiredRoutes : -1;
}

int main() {
    // Exercise-1
    int N1 = 6;
    std::vector<std::pair<int, int>> routes1 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    int result1 = minOperations(N1, routes1);
    std::cout << result1 << std::endl;

    // Exercise-2
    int N2 = 5;
    std::vector<std::pair<int, int>> routes2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}};
    int result2 = minOperations(N2, routes2);
    std::cout << result2 << std::endl;

    return 0;
}
                                                                                                                            