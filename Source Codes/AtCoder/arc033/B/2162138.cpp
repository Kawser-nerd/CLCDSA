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

  int na, nb;
  cin >> na >> nb;
  set< int > a, b, u;
  for(int i = 0; i < na; i++){
    int t;
    cin >> t;
    a.insert(t); u.insert(t);
  }
  for(int i = 0; i < nb; i++){
    int t;
    cin >> t;
    b.insert(t); u.insert(t);
  }

  int intersect = 0;
  for(int i: a){
    if(b.find(i) != b.end()) ++intersect;
  }

  double ans = (double)intersect / u.size();

  printf("%.7lf\n", ans);

  return 0;
}