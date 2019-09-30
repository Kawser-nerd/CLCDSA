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
  int x[n], y[n], h[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> h[i];
  }

  int nz = -1;
  for(int i = 0; i < n; i++){
    if(h[i] != 0){
      nz = i;
      break;
    }
  }

  int cx = -1, cy = -1, height = -1;
  if(nz != -1){
    for(cx = 0; cx <= 100; cx++){
      bool all = false;
      for(cy = 0; cy <= 100; cy++){
        height = h[nz] + abs(x[nz] - cx) + abs(y[nz] - cy);
        all = true;
        for(int i = 0; i < n; i++){
          if(h[i] != max(0, height - abs(x[i] - cx) - abs(y[i] - cy))){
            all = false;
            break;
          }
        }
        if(all) break;
      }
      if(all) break;
    }
  }
  else{
    cx = 0; cy = 0; height = INF_INT;
    for(int i = 0; i < n; i++){
      height = min(height, x[i] + y[i]);
    }
  }

  cout << cx << " " << cy << " " << height << endl;

  return 0;
}