#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// single source shortest path algo
// shortest path from one city to every other city

vector<ll>dijks(ll n ,  vector<pair<ll,ll>>adj[], int s , vector<ll>&dis){
  priority_queue<pair<ll, ll> , vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
 
  // for(int  i = 0 ; i < n ; i++){
  //   dis[i] =1e9;
  // }
  dis[1]=0;
  q.push({0 , 1});
  while(!q.empty()){
    ll distance = q.top().first;
    ll node = q.top().second;
       q.pop();
       if(dis[node] < distance)continue;
       // traverse all adjacents
       for(auto it: adj[node]){
           ll wt = it.second;
           ll node1 = it.first;
           // if found minimum update distance
           if(dis[node1] <= wt+distance)continue;
           else{
            dis[node1]= distance+wt;
            q.push({dis[node1], node1});
           }
           
       }
  }
  return dis;
}

int main(){
  ll n , m ; cin >> n >> m ;
  vector<pair<ll, ll>>adj[100001];
  int i = 0 ; 
  while(i++ <m){
       ll u , v , w;
       cin >> u >> v>>w;
       adj[u].push_back({v , w});
       adj[v].push_back({u , w});
  }
  vector<ll>dis(n ,1e9);
 dijks(n  , adj , 1 , dis);
 for(int i = 0; i <n ; i++){
  cout <<dis[i+1] << " ";
 }

}
