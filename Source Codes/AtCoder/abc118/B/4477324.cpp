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

  int n, m;
  cin >> n >> m;
  int k[n], a[n][m];
  for(int i = 0; i < n; i++){
    cin >> k[i];
    for(int j = 0; j < k[i]; j++){
      cin >> a[i][j];
    }
  }

  int count = 0;
  for(int i = 0; i < m; i++){
    bool all = true;
    for(int j = 0; j < n; j++){
      bool exist = false;
      for(int l = 0; l < k[j]; l++){
        if(a[j][l] == (i + 1)){
          exist = true;
          break;
        }
      }
      if(!exist){
        all = false;
        break;
      }
    }
    if(all) ++count;
  }

  cout << count << endl;

  return 0;
}