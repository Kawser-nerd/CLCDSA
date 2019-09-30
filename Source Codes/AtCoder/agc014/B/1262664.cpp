#include<iostream>
#include<algorithm>

using namespace std;

int cnt[108000];
int n, m, u, v;

int main(){
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    cin >> u >> v;
    cnt[u] ^= 1;
    cnt[v] ^= 1;
  }
  for(int i = 1;i <= n;i++){
    if(cnt[i]){
      cout << "NO" << endl;
      return 0;
    }
    
  }
  cout << "YES" << endl;
  return 0;
}