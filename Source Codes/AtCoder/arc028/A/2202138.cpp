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

  int n, a, b;
  cin >> n >> a >> b;

  int s = n;
  bool ant = true;
  while(s > 0){
    if(ant) s = max(s - a, 0);
    else s = max(s - b, 0);
    ant = !ant;
  }

  if(!ant) cout << "Ant" << endl;
  else cout << "Bug" << endl;

  return 0;
}