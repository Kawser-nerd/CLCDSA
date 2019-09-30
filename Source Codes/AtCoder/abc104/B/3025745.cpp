#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.length();

  if(s[0] != 'A'){
    cout << "WA" << endl;
    return 0;
  }

  int count = 0;
  for(int i = 2; i <= n - 2; i++){
    if(s[i] == 'C') ++count;
  }

  if(count != 1){
    cout << "WA" << endl;
    return 0;
  }
  
  for(int i = 0; i < n; i++){
    if(s[i] == 'A' || s[i] == 'C') continue;
    if(!('a' <= s[i] && s[i] <= 'z')){
      cout << "WA" << endl;
      return 0;
    }
  }

  cout << "AC" << endl;

  return 0;
}