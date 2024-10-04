#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and detect a cycle
bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;  // Mark the current node as visited

    // Traverse all the adjacent vertices
    for (int neighbor : adj[node]) {
        // If the neighbor is not visited, recursively call DFS
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) {
                return true;  // If cycle is found in a deeper call, return true
            }
        }
        // If the neighbor is visited and it's not the parent, we found a cycle
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;  // No cycle found in this path
}

// Function to check if the graph contains a cycle
bool containsCycle(int V, vector<pair<int, int>>& edges) {
    vector<int> adj[V];  // Adjacency list representation

    // Build the graph from the edge list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);  // To track visited vertices

    // Check all components of the graph
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {  // If the node is not visited, perform DFS
            if (dfs(i, -1, adj, visited)) {  // -1 is the parent of the root node
                return true;  // If a cycle is detected, return true
            }
        }
    }

    return false;  // No cycle detected
}

int main() {
    // Example 1: Contains a cycle
    int V1 = 5;
    vector<pair<int, int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << (containsCycle(V1, edges1) ? "true" : "false") << endl;  // Output: true

    // Example 2: No cycle
    int V2 = 3;
    vector<pair<int, int>> edges2 = {{0, 1}, {1, 2}};
    cout << (containsCycle(V2, edges2) ? "true" : "false") << endl;  // Output: false

    // Example 3: Single node, no cycle
    int V3 = 1;
    vector<pair<int, int>> edges3 = {};
    cout << (containsCycle(V3, edges3) ? "true" : "false") << endl;  // Output: false

    // Example 4: No cycle
    int V4 = 4;
    vector<pair<int, int>> edges4 = {{0, 1}, {1, 2}, {2, 3}};
    cout << (containsCycle(V4, edges4) ? "true" : "false") << endl;  // Output: false

    return 0;
}
