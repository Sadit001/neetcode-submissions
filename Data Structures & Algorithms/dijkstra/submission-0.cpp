#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        unordered_map<int, int> shortest;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});
        while (!minHeap.empty()) {
            auto [w1, n1] = minHeap.top();
            minHeap.pop();
            if (shortest.find(n1) != shortest.end()) {
                continue;
            }
            shortest[n1] = w1;
            for (const auto& neighbor : adj[n1]) {
                int n2 = neighbor.first;
                int w2 = neighbor.second;
                if (shortest.find(n2) == shortest.end()) {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (shortest.find(i) == shortest.end()) {
                shortest[i] = -1;
            }
        }
        return shortest;
    }
};