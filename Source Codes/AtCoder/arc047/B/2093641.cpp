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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int x[n], y[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }

  int min_x = INF_INT, max_x = -INF_INT;
  int min_y = INF_INT, max_y = -INF_INT;
  for(int i = 0; i < n; i++){
    min_x = min(min_x, x[i] + y[i]);
    max_x = max(max_x, x[i] + y[i]);
    min_y = min(min_y, x[i] - y[i]);
    max_y = max(max_y, x[i] - y[i]);
  }
  int r = max(max_x - min_x, max_y - min_y) / 2;

  if(DEBUG){
    cout << r << endl;
  }

  int px[4], py[4];
  px[0] = max_x - r; py[0] = max_y - r;
  px[1] = max_x - r; py[1] = min_y + r;
  px[2] = min_x + r; py[2] = max_y - r;
  px[3] = min_x + r; py[3] = min_y + r;

  for(int i = 0; i < 4; i++){
    if(DEBUG){
      cout << (to_string(px[i] + py[i]) + " " + to_string(px[i] - py[i])) << endl;
    }
    int d = abs((px[i] + py[i]) / 2 - x[0]) + abs((px[i] - py[i]) / 2 - y[0]);
    bool found = true;
    for(int j = 1; j < n; j++){
      if(d != abs((px[i] + py[i]) / 2 - x[j]) + abs((px[i] - py[i]) / 2 - y[j])){
        found = false;
        break;
      }
    }
    if(found){
      cout << (to_string((px[i] + py[i]) / 2) + " " + to_string((px[i] - py[i]) / 2)) << endl;
      return 0;
    }
  }

  return 0;
}