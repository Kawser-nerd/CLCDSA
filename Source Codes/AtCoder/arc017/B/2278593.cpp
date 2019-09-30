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
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int count = 0;
  int s = 0;
  while(s < n){
    int t = s;
    while(t + 1 < n && a[t] < a[t + 1]){
      ++t;
    }
    if(t - s + 1 >= k){
      count += (t - s + 1) - (k - 1);
    }
    s = t + 1;
  }

  cout << count << endl;

  return 0;
}