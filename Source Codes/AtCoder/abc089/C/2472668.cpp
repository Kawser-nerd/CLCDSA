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
#define MAX_N 100000
using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s[MAX_N];
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }

  const int M = 0, A = 1, R = 2, C = 3, H = 4;
  ll count[5];
  fill(count, count + 5, 0);
  for(int i = 0; i < n; i++){
    if(s[i][0] == 'M') ++count[M];
    else if(s[i][0] == 'A') ++count[A];
    else if(s[i][0] == 'R') ++count[R];
    else if(s[i][0] == 'C') ++count[C];
    else if(s[i][0] == 'H') ++count[H];
  }

  ll sum = 0;
  for(int i = 0; i < 5; i++){
    for(int j = i + 1; j < 5; j++){
      for(int k = j + 1; k < 5; k++){
        sum += count[i] * count[j] * count[k];
      }
    }
  }

  cout << sum << endl;

  return 0;
}