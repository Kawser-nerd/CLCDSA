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
  for(int i = 0; i < n; i++){
    if(!(s[i] == 'I' || s[i] == 'i')) continue;
    for(int j = i + 1; j < n; j++){
      if(!(s[j] == 'C' || s[j] == 'c')) continue;
      for(int k = j + 1; k < n; k++){
        if(s[k] == 'T' || s[k] == 't'){
          cout << "YES" << endl;
          return 0;
        }
      }
    }
  }

  cout << "NO" << endl;
  
  return 0;
}