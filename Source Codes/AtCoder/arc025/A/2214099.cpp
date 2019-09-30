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

  int d[7], j[7];
  for(int i = 0; i < 7; i++){
    cin >> d[i];
  }
  for(int i = 0; i < 7; i++){
    cin >> j[i];
  }

  int sum = 0;
  for(int i = 0; i < 7; i++){
    sum += max(d[i], j[i]);
  }

  cout << sum << endl;

  return 0;
}