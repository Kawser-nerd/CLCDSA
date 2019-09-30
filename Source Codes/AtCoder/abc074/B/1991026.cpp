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

  int n, k;
  cin >> n >> k;
  int x[n];
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }

  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += min(x[i] * 2, abs(k - x[i]) * 2);
  }

  cout << sum << endl;

  return 0;
}