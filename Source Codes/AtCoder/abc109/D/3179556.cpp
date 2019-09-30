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

  int h, w;
  cin >> h >> w;
  int a[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a[i][j];
    }
  }

  vector< vector< int > > sx, sy;
  vector< int > x, y;
  bool f = true, found = false;
  for(int i = 0; i < h; i++){
    if(f){
      for(int j = 0; j < w; j++){
        if(found || a[i][j] % 2 == 1){
          y.push_back(i); x.push_back(j);
        }
        if(a[i][j] % 2 == 1){
          if(found){
            sy.push_back(y); sx.push_back(x);
            x.clear(); y.clear();
          }
          found = !found;
        }
      }
    }
    else{
      for(int j = w - 1; j >= 0; j--){
        if(found || a[i][j] % 2 == 1){
          y.push_back(i); x.push_back(j);
        }
        if(a[i][j] % 2 == 1){
          if(found){
            sy.push_back(y); sx.push_back(x);
            x.clear(); y.clear();
          }
          found = !found;
        }
      }
    }
    f = !f;
  }

  string buf;
  int n = 0;
  for(int i = 0; i < sx.size(); i++){
    for(int j = 0; j + 1 < sx[i].size(); j++){
      buf += to_string(sy[i][j] + 1) + " " +
        to_string(sx[i][j] + 1) + " ";
      buf += to_string(sy[i][j + 1] + 1) + " " +
        to_string(sx[i][j + 1] + 1) + "\n";
      ++n;
    }
  }

  cout << n << endl;
  cout << buf;

  return 0;
}