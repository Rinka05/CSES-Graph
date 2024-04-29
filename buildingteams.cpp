#include <bits/stdc++.h>
using namespace std;


// run bfs and check if neighbouring nodes are of same color as its parents 

vector<int>graph[100005];
queue<int>q;


bool bfs(int s, vector<int>&visited , vector<int>&answer ){
   visited[s] = 1;
    q.push(s);
    answer[s] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : graph[node]){
           if(answer[it] == answer[node]) return false;
           if(visited[it])continue;
           visited[it] = visited[node]+1;
           answer[it] = (answer[node] ==1?2:1);
           q.push(it);
        }
    }
  return true;
}

int main(){
    int n ,m ; cin >> n >> m ;

  for(int i = 0 ; i <m ; i++){
    int u , v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
vector<int>visited(n+1 , 0);
vector<int>answer(n+1 , 0);
for(int i = 1 ; i <=n ; i++){
    if(!visited[i]){
    if(!bfs(i , visited , answer)){
    cout << "IMPOSSIBLE" << endl;
    return 0;
    }
    }
}
for(int i = 1; i <=n ; i++){
    cout << answer[i] << " ";
}


}