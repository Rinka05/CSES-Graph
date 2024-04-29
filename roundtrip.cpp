#include <bits/stdc++.h>
using namespace std;

// cycle detection and cycle formed both should be returned

 // logic is if we visit a node and it is not 
 // the parent but already visited then it contains a cycle

// algo 
// dfs , marking the parent
// for every neighbour 
// if it is unvisited do dfs into that neighbour 
// if its visited 
// if its parent np 
// else its a cycle 
// cycle detected and retrieved when we revisit a non-parent neighbour









vector<int>graph[100005];
vector<int>cycle;

vector<int>path;
bool a = false ;
int sv = -1 , ev = -1;
bool dfs(int src , vector<int>graph[] , vector<int>&visited , vector<int>& parent){
    visited[src]= 1;
    for(auto it : graph[src]){
       if(it == parent[src])continue;
      if(!visited[it]){
        visited[it]= 1;
         parent[it] = src;
        if(dfs(it , graph , visited , parent)) return true;
      }
      if(visited[it] ==1 && parent[src] != it){
          sv = it;
          ev = src;
          return true;
      }

    }
    return false;
}

int main(){
    int n ,  m ; cin >> n >> m ;
   for(int i = 0 ; i < m ; i++){
    int u , v ; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
   }
   vector<int> visited(n+1 , 0);
   vector<int>parent(n+1 , -1);
  bool check = 0 ;
  for(int i = 1 ; i <= n ; i++){
   if(!visited[i]){
  if(dfs(i , graph , visited , parent )){
    check =1 ;
    break;
       }
   }
  }

  if( check == 0){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  // cout << sv << " " << ev << endl;
  int r = ev;
   vector<int> ans ;
   ans.push_back(ev);
   while( sv != ev){
    ev = parent[ev];
     ans.push_back(ev); 
   }

 
   ans.push_back(r);
  //  for(int i = 0 ; i < n ; i++){
  //   cout << parent[i+1] << " ";
  //  }
  //  cout << endl;
   
   cout << ans.size() << endl;
   for(auto it : ans){
    cout << it << " ";
   }
   cout << endl;
}


