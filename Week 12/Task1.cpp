#include<iostream>
#include<vector>
#include<fstream>
using std::vector;
int main() {
    std::ofstream output("job.out");
    std::ifstream input("job.txt");
    int V,E;
    input>>V>>E;
    vector<vector<int>> adj(V + 1);
    for (int i = 0; i < E; i++) {
        int u,v;
        input>>u>>v;
        adj[u].push_back(v);
    }
    //kahn algorithm
    vector<int> k(V + 1);
    for (int i = 1; i <= V; i++) {
        for (auto j : adj[i]) {
            k[j]++;
        }
    }
    vector<int> queue;
    for (int i = 1; i < V; i++) {
        if (k[i] == 0) {
            queue.push_back(i);
        }
    }
    vector<int> result;
    while(!queue.empty()) {
        int node = queue.front();
        queue.erase(queue.begin());
        result.push_back(node);
        for (auto j : adj[node]) {
            k[j]--;
            if (k[j] == 0) {
                queue.push_back(j);
            }
        }
    }
    for (auto i : result) {
        output<<i<<" ";
    }
}
