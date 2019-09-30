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

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b;
  cin >> n >> a >> b;
  int s[n];
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }

  ll sum = 0;
  int mx = 0, mi = INF_INT;
  for(int i = 0; i < n; i++){
    mx = max(mx, s[i]);
    mi = min(mi, s[i]);
    sum += s[i];
  }

  if(mx == mi){
    if(b != 0){
      cout << -1 << endl;
    }
    else if(s[0] != 0){
      cout << to_string((double) a / s[0]) + " 0" << endl;
    }
    else{
      cout << "0 " + to_string(a) << endl;
    }
    return 0;
  }

  double pp = (double)b / (mx - mi);
  //double pm = (double)b / (mi - mx);
  double qpp = - (pp / n) * sum + a;
  //double qpm = - (pm / n) * sum + a;

  cout << to_string(pp) + " " + to_string(qpp) << endl;

  return 0;
}