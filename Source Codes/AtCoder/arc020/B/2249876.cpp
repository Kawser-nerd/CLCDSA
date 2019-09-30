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

  int n, c;
  cin >> n >> c;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = INF_INT;
  for(int i = 1; i <= 10; i++){
    for(int j = 1; j <= 10; j++){
      if(i == j) continue;
      int sum = 0;
      for(int k = 0; k < n; k++){
        if(k % 2 == 0){
          if(a[k] != i) sum += c;
        }
        else{
          if(a[k] != j) sum += c;
        }
      }
      ans = min(ans, sum);
    }
  }

  cout << ans << endl;

  return 0;
}