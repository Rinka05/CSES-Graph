#include <bits/stdc++.h>
using namespace std;


//bulb 
// i am storing head node of every disconnected component and then later we can join them 
// first node of every new dfs iteration will be head node of disconnected component



 vector<int>graph[100005];


void dfs(int x, int n, vector<int>&visited ){
    if(visited[x] ==1) return ;
    visited[x] =1;
    for(auto i : graph[x]){
        dfs(i , n , visited);
    }
    
}

int main(){
    int n , m ; cin >>  n >> m ;
        for(int i = 0 ; i <m ; i++ ){
           int u , v ; cin >> u >> v;
           graph[u].push_back(v);
           graph[v].push_back(u);
    }
    vector<int>visited(n+1 , 0);
    vector<int> answer;
    for(int i = 1 ; i < n+1 ; i++){
        if(visited[i] ==0){
            answer.push_back(i);
            dfs(i , n , visited);

        }
    }
    cout << answer.size()-1 << endl;
    for(int i = 1 ; i < answer.size(); i++){
        cout << answer[i] << " " << answer[i-1] << endl;
    }

}




