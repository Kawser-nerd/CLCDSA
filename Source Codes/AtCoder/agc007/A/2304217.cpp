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
#define MAX_H 8
using namespace std;

int h, w;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w;
  string a[MAX_H];
  for(int i = 0; i < h; i++){
    cin >> a[i];
  }

  int count = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j] == '#') ++count;
    }
  }

  if(count == h + w - 1){
    cout << "Possible" << endl;
  }
  else{
    cout << "Impossible" << endl;
  }

  return 0;
}