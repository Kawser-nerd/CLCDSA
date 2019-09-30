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

  int n, l;
  string s;
  cin >> n >> l;
  cin >> s;

  int sum = 1, count = 0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '+') ++sum;
    else --sum;
    if(sum > l){
      ++count;
      sum = 1;
    }
  }

  cout << count << endl;

  return 0;
}