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
  string s[100001];
  for(int i=0; i<n; i++) cin >> s[i];

  ll count[5] = {0};
  string march="MARCH";

  for(int i=0; i<n; i++){
    for(int j=0; j<5; j++){
      if(march[j] == s[i][0]) count[j]++;
    }
  }

  ll ans = 0;
  for(int i=0; i<5; i++){
    for(int j=i+1; j<5; j++){
      if(i==j) continue;
      for(int k=j+1; k<5; k++){
        if(i==k || j==k) continue;
        ans += count[i]*count[j]*count[k];
      }
    }
  }
  cout << ans << endl;
}