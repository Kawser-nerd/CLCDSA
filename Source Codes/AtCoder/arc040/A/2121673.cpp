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
#define MAX_N 100
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s[MAX_N];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }

  int red = 0, blue = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(s[i][j] == 'R') ++red;
      if(s[i][j] == 'B') ++blue;
    }
  }

  if(red > blue) cout << "TAKAHASHI" << endl;
  else if(red < blue) cout << "AOKI" << endl;
  else cout << "DRAW" << endl;

  return 0;
}