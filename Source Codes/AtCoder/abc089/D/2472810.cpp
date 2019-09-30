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
#define MAX_H 300
#define MAX_W 300
#define MAX_D (MAX_H * MAX_W)
#define MAX_Q 100000
using namespace std;

typedef pair< int, int > pii;

int h, w, d;
int a[MAX_H][MAX_W];
int q;
int l[MAX_Q], r[MAX_Q];

int cost(pii p1, pii p2){
  return abs(p1.first - p2.first) + 
    abs(p1.second - p2.second);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w >> d;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a[i][j];
      --a[i][j];
    }
  }
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> l[i] >> r[i];
    --l[i]; --r[i];
  }

  pii s[MAX_H * MAX_W];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      s[a[i][j]] = make_pair(j, i);
    }
  }

  int c[d][(MAX_H * MAX_W) / d + 1];
  for(int i = 0; i < d; i++){
    c[i][0] = 0;
    for(int j = 1; i + d * j < MAX_H * MAX_W; j++){
      c[i][j] = c[i][j - 1] + 
        cost(s[i + (j - 1) * d], s[i + j * d]);
    }
  }

  string buf;
  for(int i = 0; i < q; i++){
    int start = l[i] % d;
    int ans = c[start][r[i] / d] - c[start][l[i] / d];
    buf += to_string(ans) + "\n";
  }

  cout << buf;

  return 0;
}