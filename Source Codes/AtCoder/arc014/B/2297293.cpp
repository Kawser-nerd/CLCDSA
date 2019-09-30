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
  cin >> n;
  string w[MAX_N];
  for(int i = 0; i < n; i++){
    cin >> w[i];
  }

  bool a = false;
  set< string > said;
  said.insert(w[0]);
  for(int i = 1; i < n; i++){
    int l0 = w[i - 1].length();
    if(w[i - 1][l0 - 1] != w[i][0] ||
        said.find(w[i]) != said.end()){
      if(a) cout << "LOSE" << endl;
      else cout << "WIN" << endl;
      return 0;
    }
    said.insert(w[i]);
    a = !a;
  }

  cout << "DRAW" << endl;

  return 0;
}