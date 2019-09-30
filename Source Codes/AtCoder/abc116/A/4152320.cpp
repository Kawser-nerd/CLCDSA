#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int a,b,c; cin >> a >> b >> c;
  	int ans;
 	if(a > b && a > c) ans = (b * c) / 2;
  else if(b > a && b > c) ans = (a * c) / 2;
  else ans = (a*b) / 2;
  cout << ans << endl;
    return 0;
}