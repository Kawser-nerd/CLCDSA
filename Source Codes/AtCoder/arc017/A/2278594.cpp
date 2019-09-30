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

  bool prime = true;
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      prime = false;
      break;
    }
  }

  if(prime) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}