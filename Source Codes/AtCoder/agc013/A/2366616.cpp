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
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  if(n <= 2){
    cout << 1 << endl;
    return 0;
  }

  bool all = true;
  for(int i = 0; i + 1 < n; i++){
    if(a[i] != a[i + 1]){
      all = false;
      break;
    }
  }
  if(all){
    cout << 1 << endl;
    return 0;
  }


  int s = 0;
  int count = 0;
  while(s < n){
    int t = s;
    int f = 0;
    while(t + 1 < n){
      if(a[t] == a[t + 1]) ++t;
      else if(a[t] < a[t + 1]){
        if(f == 0 || f == 1){
          f = 1;
          ++t;
        }
        else break;
      }
      else if(a[t] > a[t + 1]){
        if(f == 0 || f == 2){
          f = 2;
          ++t;
        }
        else break;
      }
      else break;
    }
    ++count;
    s = t + 1;
  }

  cout << count << endl;

  return 0;
}