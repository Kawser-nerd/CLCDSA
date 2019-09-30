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
  vector< string > tab(h);
  for(int i = 0; i < h; i++) cin >> tab[i];

  bool r[h], c[w];
  fill(r, r + h, false);
  fill(c, c + w, false);
  for(int i = 0; i < h; i++){
    bool found = false;
    for(int j = 0; j < w; j++){
      if(tab[i][j] == '#'){
        found = true;
        break;
      }
    }
    r[i] = found;
  }
  for(int j = 0; j < w; j++){
    bool found = false;
    for(int i = 0; i < h; i++){
      if(tab[i][j] == '#'){
        found = true;
        break;
      }
    }
    c[j] = found;
  }

  vector< string > ans;
  for(int i = 0; i < h; i++){
    if(!r[i]) continue;
    string s;
    for(int j = 0; j < w; j++){
      if(c[j]) s.push_back(tab[i][j]);
    }
    ans.push_back(s);
  }

  string buf;
  for(string s: ans){
    buf += s + "\n";
  }

  cout << buf;

  return 0;
}