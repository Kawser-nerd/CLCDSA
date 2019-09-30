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

  bool ans = false;
  for(int i = 0; !ans && 4 * i <= n; i++){
    for(int j = 0; !ans && 4 * i + 7 * j <= n; j++){
      if(n == 4 * i + 7 * j){
        ans = true;
        break;
      }
    }
  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}