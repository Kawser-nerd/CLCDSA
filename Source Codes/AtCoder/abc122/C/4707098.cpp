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

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int l[q], r[q];
  for(int i = 0; i < q; i++){
    cin >> l[i] >> r[i];
    --l[i]; --r[i];
  }

  int t[n + 1];
  fill(t, t + n + 1, 0);
  for(int i = 2; i <= n; i++){
    if(s[i - 1] == 'C' && s[i - 2] == 'A'){
      t[i] = t[i - 2] + 1;
    }
    else{
      t[i] = t[i - 1];
    }
  }

  string buf;
  for(int i = 0; i < q; i++){
    int ans = t[r[i] + 1] - t[l[i]];
    if(l[i] - 1 >= 0 && s[l[i] - 1] == 'A' && s[l[i]] == 'C') --ans;
    buf += to_string(ans) + "\n";
  }

  cout << buf;

  return 0;
}