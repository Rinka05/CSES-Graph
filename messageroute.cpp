#include <bits/stdc++.h>
using namespace std;



// single source shortest path 
// if we do dfs we will loose distance of nodes
// we do bfs from node and store parent of every node








vector<int> graph[100005];
queue<int>q;

void bfs(int s , vector<int>&visited , vector<int>&parent){
    visited[s] =1;
    q.push(s);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(auto i: graph[s]){
            if(visited[i] ==1)continue;
            if(visited[i] == 0){
                visited[i] = 1;
                parent[i]= s;
                q.push(i);
            }
        }
    }
}


int main(){
    int n ,m ; cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int u , v ; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>visited(n+1 , 0);
    vector<int>parent(n+1 , 0);
    bfs(1 , visited , parent);
    


    int node = n;
    vector<int>p;
    if(visited[n] == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else {
    while(node != 1){
        p.push_back(node);
        node = parent[node];
    }
    p.push_back(1);

    cout << p.size() << endl;
    for(int i = p.size()-1 ; i>= 0 ; i--){
        cout << p[i]  << " ";
    }

    }
    

}