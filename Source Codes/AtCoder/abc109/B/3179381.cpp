#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector< string > w(n);
  for(int i = 0; i < n; i++) cin >> w[i];

  bool ans = true;
  for(int i = 1; i < w.size(); i++){
    for(int j = 0; j < i; j++){
      if(w[i] == w[j]){
        ans = false;
        break;
      }
    }
    if(w[i - 1][w[i - 1].length() - 1] != w[i][0]){
      ans = false;
      break;
    }
    if(!ans) break;
  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}