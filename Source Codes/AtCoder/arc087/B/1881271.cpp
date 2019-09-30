#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

bool xdp[8001][20000];
bool ydp[8001][20000];
int os=10000;

int main(){

  string s;
  cin >> s;
  int x,y;
  cin >> x >> y;
  int n = s.length();
  int cur = 0;
  vector<int> f(n,0);
  rep(i,n){
    if (s[i] == 'T'){
      cur++;
    } else {
      f[cur]++;
    }
  }

  rep(i,n){
    for(int k=-8000;k<8001;k++){
      xdp[i][os+k]=false;
      ydp[i][os+k]=false;
    }
  }

  xdp[0][os+f[0]]=true;
  ydp[0][os]=true;

  rep(i,n-1){
    for(int k=-8000;k<8001;k++){
      if(i%2==0){
        xdp[i+1][os+k]=xdp[i][os+k];
        ydp[i+1][os+k]=ydp[i][os+k-f[i+1]] | ydp[i][os+k+f[i+1]];
      } else {
        xdp[i+1][os+k]=xdp[i][os+k-f[i+1]] | xdp[i][os+k+f[i+1]];
        ydp[i+1][os+k]=ydp[i][os+k];
      }
    }
  }
  if (xdp[n-1][os+x]&ydp[n-1][os+y]){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}