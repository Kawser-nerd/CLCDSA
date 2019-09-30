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

  string s;
  cin >> s;

  int n = s.length();
  for(int i = 0; i < n; i++){
    switch(s[i]){
      case 'O': case 'D': s[i] = '0'; break;
      case 'I': s[i] = '1'; break;
      case 'Z': s[i] = '2'; break;
      case 'S': s[i] = '5'; break;
      case 'B': s[i] = '8'; break;
    }
  }

  cout << s << endl;

  return 0;
}