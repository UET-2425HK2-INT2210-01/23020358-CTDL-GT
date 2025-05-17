#include<iostream>
#include<vector>
#include<fstream>
using std::vector;
std::ofstream output("connection.out");
std::ifstream input("connection.txt");

int getminKey(vector<int> &key, vector<bool> &inMst) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < inMst.size(); v++)
        if (inMst[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void mspt() {
    int V, E;
    input>>V>>E;
    vector<vector<int>> graph(V + 1,vector<int>(V + 1));
    for (int i = 0; i < E; i++) {
        int u,v,d;
        input>>u>>v>>d;
        graph[u][v] = d;
        graph[v][u] = d;
    }
    vector<int> parent(V + 1);
    parent[0] = -1;
    vector<int> key(V + 1, INT_MAX);
    key[1] = 0;
    vector<bool> inMst(V + 1, false);
    for (int i = 1; i <= V; i++) {
        int u = getminKey(key,inMst);
        inMst[u] = true;
        for (int i = 1; i <= V; i ++) {
            if (graph[u][i] < key[i] && inMst[i] == false && graph[u][i] != 0) {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    int totalcost = 0;
    for (int i = 1; i <= V; i++) {
        totalcost += graph[parent[i]][i];
    }
    output<<totalcost<<std::endl;
    for (int i = 2; i < graph.size(); i++)
        output<<parent[i]<<" "<<i<<" "<<graph[parent[i]][i]<<std::endl;
}
int main(){
    mspt();
}