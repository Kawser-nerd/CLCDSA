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

  int n, r;
  string s;
  cin >> n >> r;
  cin >> s;

  for(int i = n - 1; i >= 0; i--){
    if(s[i] == 'o') --n;
    else break;
  }

  int t = 0;
  int i = 0;
  while(i < n){
    if(s[i] == 'o' && i + r - 1 < n - 1) ++i;
    else{
      for(int j = i; j < min(n, i + r); j++){
        s[j] = 'o';
      }
    }
    ++t;
    if(s[n - 1] == 'o') break;
  }

  cout << t << endl;

  return 0;
}