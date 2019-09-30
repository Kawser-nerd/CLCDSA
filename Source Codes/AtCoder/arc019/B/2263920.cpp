#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.length();
  int count = 0;
  for(int i = 0; i < n / 2; i++){
    if(s[i] != s[n - 1 - i]) ++count;
  }

  int ans;
  if(count == 0){
    if(n % 2 == 1) ans = (n - 1) * 25;
    else ans = n * 25;
  }
  else if(count == 1){
    ans = (n - 2) * 25 + 24 * 2;
  }
  else{
    ans = n * 25;
  }

  cout << ans << endl;

  return 0;
}