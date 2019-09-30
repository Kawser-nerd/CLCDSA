#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<climits>
#include<cstdlib>
#include<map>
#include<math.h>
#include<utility>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  int c[510], s[510], f[501];
  for(int i=0; i<n-1; i++) cin >> c[i] >> s[i] >> f[i];

  ll ans[510];
  for(int j=0; j<n; j++){
    int now=0;
    for(int i=j; i<n-1; i++){
      if(now < s[i]) now = s[i];
      if(now%f[i] != 0) now += f[i] - now%f[i];
      now += c[i];
    }
    ans[j] = now;
  }
  for(int i=0; i<n; i++){
    cout << ans[i] << endl;
  }
}