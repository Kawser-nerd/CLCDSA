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

  if(n == 1){
    cout << "BOWWOW" << endl;
    return 0;
  }

  int m = n * (n + 1) / 2;
  for(int j = 2; j * j <= m; j++){
    if(m % j == 0){
      cout << "BOWWOW" << endl;
      return 0;
    }
  }
  cout << "WANWAN" << endl;

  return 0;
}