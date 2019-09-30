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

  string s;
  cin >> s;

  int n = s.length();

  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j <= n; j++){
      string t = s.substr(i, (j - i));
      bool found = false;
      for(char c: t){
        if(!(c == 'A' || c == 'C' || c == 'G' || c == 'T')){
          found = true;
          break;
        }
      }
      if(!found) ans = max(ans, (int)t.length());
    }
  }

  cout << ans << endl;

  return 0;
}