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

  int t = s.length() - 1;
  while(t > 1){
    if(t % 2 == 1) --t;
    bool even = true;
    for(int i = 0; i < t / 2; i++){
      if(s[i] != s[t / 2 + i])
        even = false;
    }
    if(even) break;
    --t;
  }

  cout << t << endl;

  return 0;
}