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

  int n;
  cin >> n;
  int b[n];
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }

  int a[n];
  a[0] = 0;
  for(int i = 1; i < n; i++){
    a[i] = b[i - 1] ^ a[i - 1];
  }

  if(b[n - 1] != (a[0] ^ a[n - 1])){
    cout << -1 << endl;
    return 0;
  }

  string s;
  for(int i = 0; i < n; i++){
    s += to_string(a[i]) + "\n";
  }

  cout << s;

  return 0;
}