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
using namespace std;

class PlaneSum{
  public:
    int h, w;
    vector< vector< int > > s;

    PlaneSum(int h, int w, vector< vector< int > > c){
      this->h = h; this->w = w;

      s.resize(h);
      for(int i = 0; i < h; i++){
        s[i].resize(w);
      }

      s[0][0] = c[0][0];
      for(int i = 1; i < h; i++){
        s[i][0] = s[i - 1][0] + c[i][0];
      }
      for(int i = 1; i < w; i++){
        s[0][i] = s[0][i - 1] + c[0][i];
      }

      for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
          s[i][j] = s[i - 1][j] + s[i][j - 1] + c[i][j] - s[i - 1][j - 1];
        }
      }
    }

    int sum(int i, int j, int k, int l){
      return get(k, l) - get(i - 1, l) - get(k, j - 1) + get(i - 1, j - 1);
    }

    int get(int i, int j){
      if(i < 0 || j < 0) return 0;
      return s[i][j];
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector< vector< int > >  b(h), s(h);
  for(int i = 0; i < h; i++){
    b[i].resize(w); s[i].resize(w);
    for(int j = 0; j < w; j++){
      int c;
      cin >> c;
      if(i % 2 == j % 2) b[i][j] = c;
      else s[i][j] = c;
    }
  }

  PlaneSum black(h, w, b);
  PlaneSum white(h, w, s);

  int ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      for(int k = i; k < h; k++){
        for(int l = j; l < w; l++){
          if(black.sum(i, j, k, l) == white.sum(i, j, k, l)){
            ans = max(ans, (k - i + 1) * (l - j + 1));
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}