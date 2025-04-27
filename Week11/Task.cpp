#include<iostream>
#include<vector>
#include<fstream>
using std::cin, std::cout, std::vector;
//print path from this vertex to other vertex
void printPath(vector<vector<int>> &pre, int start, int end, std::ofstream &output) {
    vector<int> path;
    path.push_back(end);
    while (end != start) {
        end = pre[start][end];
        path.insert(path.begin(), end);
    }
    for (int i : path) {
        output<<i<<" ";
    }
    output<<std::endl;
}
//Floyd–Warshall algorithm
void Floyd() {
    std::ifstream input("dirty.txt");
    std::ofstream output("dirty.out");
    int v, e, start,end;
    input>>v>>e>>start>>end;
    //vector to save value of weight of edge
    vector<vector<int>> dist(v + 1, vector<int>(v + 1,INT_MAX));
    //track vertices
    vector<vector<int>> pre(v + 1,vector<int>(v + 1,0));
    //implementation
    for (int i = 0; i < e; i ++) {
        int a,b,u;
        input>>a>>b>>u;
        dist[a][b] = u;
        pre[a][b] = a;
        dist[a][a] = 0;
        dist[b][b] = 0;
        pre[a][a] = a;
        pre[b][b] = b;
    }
    //Floyd–Warshall algorithm with path tracking
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (dist[i][k] != INT_MAX 
                    && dist[k][j] != INT_MAX 
                    && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }
    output<<dist[start][end]<<std::endl;
    printPath(pre,start,end,output);
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            (dist[i][j] != INT_MAX) ? output<<dist[i][j]<<" " : output<<"INF"<<" ";
        }
        output<<std::endl;
    }
} 

int main() {
    Floyd();
}
