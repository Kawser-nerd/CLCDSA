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
  int a, b;
  cin >> n;
  cin >> a >> b;

  if(a >= n){
    cout << "Takahashi" << endl;
    return 0;
  }

  if(a == b){
    if(n % (a + 1) == 0){
      cout << "Aoki" << endl;
    }
    else{
      cout << "Takahashi" << endl;
    }
  }
  else{
    if(a < b){
      cout << "Aoki" << endl;
    }
    else{
      cout << "Takahashi" << endl;
    }
  }

  return 0;
}