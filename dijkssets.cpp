#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>dijks(ll n ,  vector<pair<ll,ll>>adj[], ll s, vector<ll>&dis){
  set<pair<ll, ll>>st;

  dis[s]=0;
  st.insert({0 , s});
  while(!st.empty()){
    auto it = *(st.begin());
    ll node = it.second;
    ll d = it.first;
    st.erase(it);
       // traverse all adjacents
       for(auto it: adj[node]){
          ll wt = it.second;
           ll node1 = it.first;
           // if found minimum update distance
           if(d+wt < dis[node1]){
            dis[node1]= d+wt;
            if(dis[node1] != 1e9){
                st.erase({dis[node1], node1});
            }
            dis[node1]= d+wt;
            st.insert({dis[node1], node1});
           }
       }
  }
  return dis;
}



int main(){
 ll n , m ; cin >> n >> m ;
  vector<pair<ll, ll>>adj[100001];
  ll i = 0 ; 
  while(i++ <m){
       ll u , v , w;
       cin >> u >> v>>w;
       adj[u].push_back({v , w});
       adj[v].push_back({u , w});
  }
 vector<ll>dis(n , 1e9);
 dijks(n  , adj , 1, dis);
 for(int i = 0 ; i < n ; i++){
  cout <<dis[i+1] << " ";
 }

}
