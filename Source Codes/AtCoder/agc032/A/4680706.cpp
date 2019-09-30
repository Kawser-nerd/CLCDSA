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

const int MAX = 100001;
const int MOD = 1000000007;

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
  vector< int > b(n);
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }

  int c[n];
  bool ok = true;
  for(int i = n - 1; i >= 0; i--){
    int j = b.size() - 1;
    for(; j >= 0; j--){
      if(b[j] == j + 1) break;
    }
    if(j < 0){
      ok = false;
      break;
    }
    c[i] = j + 1;
    b.erase(b.begin() + j);
  }

  if(!ok){
    cout << -1 << endl;
    return 0;
  }

  string buf;
  for(int i = 0; i < n; i++){
    buf += to_string(c[i]) + "\n";
  }

  cout << buf;

  return 0;
}