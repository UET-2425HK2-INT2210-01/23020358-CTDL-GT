#include<iostream>
#include<vector>
using std::cin, std::cout, std::vector;
int m,n;
//use dfs to search all node in a component
void dfs(vector<vector<int>> &graph, int u, vector<bool> &visited) {
    visited[u] = true;
    for (int i : graph[u]) {
        if (!visited[i]) {
            dfs(graph,i, visited);
        }
    }
}
//count Components
int countComponents(vector<vector<int>> &graph, vector<bool> &visited) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        //if the node is visited then it will in other component
        //if not then it in new component, which is not visited
        if (!visited[i]) {
            cnt++;
            dfs(graph, i, visited);
        }
    }
    return cnt;
}
void input() {
    cin>>m>>n;
    //m : Node 
    //n : edge
    vector<vector<int>> adj(m + 1);
    vector<bool> visited(m + 1, false);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<countComponents(adj, visited);
}

int main() {
    input();
}