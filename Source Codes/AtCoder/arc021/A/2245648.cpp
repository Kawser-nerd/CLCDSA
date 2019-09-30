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

  int a[4][4];
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      cin >> a[i][j];
    }
  }

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {-1, 0, 1, 0};
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        int ni = i + dy[k];
        int nj = j + dx[k];
        if(!((0 <= ni && ni < 4) && (0 <= nj && nj < 4))) continue;
        if(a[i][j] == a[ni][nj]){
          cout << "CONTINUE" << endl;
          return 0;
        }
      }
    }
  }

  cout << "GAMEOVER" << endl;

  return 0;
}