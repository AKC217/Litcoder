#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

bool isBipartiteHelper(const std::vector<std::vector<int>>& graph, int node, std::vector<int>& color) {
    std::queue<int> q;
    q.push(node);
    color[node] = 0; // Assign color 0 to the starting node

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[curr]; // Assign the opposite color
                q.push(neighbor);
            } else if (color[neighbor] == color[curr]) {
                return false; // If adjacent nodes have the same color, the graph is not bipartite
            }
        }
    }

    return true;
}

bool isBipartite(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> color(n, -1); // Initialize colors to -1 (unvisited)

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1 && !isBipartiteHelper(graph, i, color)) {
            return false;
        }
    }

    return true;
}

int main() {
    // Exercise-1
    std::vector<std::vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    std::cout <<(isBipartite(graph1) ? "true" : "false") << std::endl;

    // Exercise-2
    std::vector<std::vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1}, {0}};
    std::cout <<(isBipartite(graph2) ? "true" : "false") << std::endl;

    // Exercise-3
    std::vector<std::vector<int>> graph3 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    std::cout <<(isBipartite(graph3) ? "true" : "false") << std::endl;

    return 0;
}
                                                                                                                            