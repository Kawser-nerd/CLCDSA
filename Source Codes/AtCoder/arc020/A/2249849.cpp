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

  int a, b;
  cin >> a >> b;

  int t = abs(a) - abs(b);
  if(t < 0){
    cout << "Ant" << endl;
  }
  else if(t > 0){
    cout << "Bug" << endl;
  }
  else{
    cout << "Draw" << endl;
  }

  return 0;
}