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

  int l, r;
  cin >> l >> r;
  int sl[l], sr[r];
  for(int i = 0; i < l; i++){
    cin >> sl[i];
  }
  for(int i = 0; i < r; i++){
    cin >> sr[i];
  }

  int count = 0;
  bool used[r];
  fill(used, used + r, false);
  for(int i = 0; i < l; i++){
    for(int j = 0; j < r; j++){
      if(!used[j] && sl[i] == sr[j]){
        used[j] = true;
        ++count;
        break;
      }
    }
  }

  cout << count << endl;

  return 0;
}