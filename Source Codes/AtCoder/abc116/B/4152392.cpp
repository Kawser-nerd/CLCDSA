#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

bool c[10000000];
int main(){
    int s; cin >> s;
    rep(i,10000000) c[i] = false;
  int ans = 0;
  	while(1){
      ans++;
      if(c[s]){ break;}
      
      c[s] = true;
      if(s % 2) s = 3*s+1;
      else s = s / 2 ;
    }
  cout << ans << endl;
    return 0;
}