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
  char x[n][9];
  for(int i = 0; i < n; i++){
    string line;
    cin >> line;
    for(int j = 0; j < 9; j++){
      x[i][j] = line[j];
    }
  }

  int count = 0;
  for(int i = 0; i < 9; i++){
    int j = 0;
    while(j < n){
      if(x[j][i] == 'x'){
        ++count;
      }
      else if(x[j][i] == 'o'){
        ++count;
        while(j + 1 < n && x[j + 1][i] == 'o') ++j;
      }
      ++j;
    }
  }

  cout << count << endl;

  return 0;
}