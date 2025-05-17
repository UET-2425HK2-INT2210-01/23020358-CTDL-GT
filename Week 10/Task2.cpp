#include<iostream>
#include<vector>
using std::vector,std::cin,std::cout;
//breadth first search just fit enough for the problem
void bfs(vector<vector<int>> &arr, vector<bool> &visited, vector<int> &parent, int u) {
    vector<int> queue;
    queue.push_back(u);
    visited[u] = true;
    while(!queue.empty()) {
        int v = queue.front();
        queue.erase(queue.begin());
        for (int i : arr[v]) {
            if (!visited[i]) {
                queue.push_back(i);
                visited[i] = true;
                parent[i] = v;
            }
        }
    }
}
//track edges and find path
//lass wir uns diese scheiße Problem lösen
int path(vector<vector<int>> &arr, vector<bool> &visited, vector<int> &parent, int zweck, int beginnen) {
    bfs(arr,visited,parent,beginnen);
    int count = 0;
    while(zweck != beginnen) {
        count++;
        zweck = parent[zweck];
    }
    return count;
}
int main() {
    int m,n,start,end;
    cin>>m>>n>>start>>end;
    vector<vector<int>> arr(m + 1);
    vector<int> parent(m + 1);
    vector<bool> visited(m + 1, false);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
    }
    cout<<path(arr,visited,parent,end,start);
}