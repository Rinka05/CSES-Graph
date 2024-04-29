#include <bits/stdc++.h>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool possible(int x , int y , int n , int m){
  if(x<n && x >= 0 && y<m && y>=0)
    return true;
  return false ;
  
}


int main(){
    int n , m ; cin >> n >> m ;
    vector<vector<int>>graph(n , vector<int>(m ,0));
   pair<int, int>a , b;
    for(int i = 0 ; i < n ; i++){
        string s ; cin >> s ;
        for(int j = 0 ; j <m ; j++ ){
            if(s[j] == '.'){
                graph[i][j] = 1;
            }
            if(s[j] == 'A'){
                a = {i, j};
            }
             if(s[j] == 'B'){
                a = {i, j};
            }
        }
    }
    vector<vector<int>>visited(n , vector<int>(m ,-1));






}