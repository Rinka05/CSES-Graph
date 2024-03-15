#include <bits/stdc++.h>
using namespace std;


int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool possible(int x , int y , int n , int m){
  if(x<n && x >= 0 && y<m && y>=0)
    return true;
  return false ;
  
}
void dfs(int x , int y ,int n , int m , vector<vector<int>>&graph,vector<vector<int>>&visited ){
  if(!possible(x, y, n , m) || visited[x][y] != -1 || graph[x][y] == 0)return ;
  visited[x][y] =1;
  for(int i = 0 ; i < 4 ; i++){
    int nx= x+dx[i] ,ny = y+dy[i];
    dfs(nx , ny, n , m , graph , visited);
  }
}
int main(){
    int n ,m ;
    cin >> n >> m ;
    vector<vector<int>>graph(n , vector<int>(m ,0));

    for(int i = 0 ; i < n ; i++){
        string s ; cin >> s ;
        for(int j = 0 ; j <m ; j++ ){
            if(s[j] == '.'){
                graph[i][j] = 1;
            }
        }
    }
    vector<vector<int>>visited(n , vector<int>(m ,-1));
 int ans = 0;
 for(int i = 0 ; i < n  ; i++){
    for(int j = 0 ; j < m ; j++){
        if(graph[i][j] ==1 && visited[i][j] ==-1){
            dfs(i  , j , n , m , graph , visited);
           ans++;
        }
    }
 }
cout << ans << endl;
}