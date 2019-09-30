#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const ll LL_INF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A, B;
  cin >> A >> B;
  // A
  string ans[102];
  int h = 0, w = 100;
  B--;
  for(int c = 0;A > 1; c++){
    h++;
    if(c & 1){
      REP(i,w) ans[h - 1] += '#'; 
    }else{
      REP(i, w){
        if(i & 1 && A > 1){
          ans[h - 1] += '.';
          A--;
        }else{
          ans[h - 1] += '#';
        }
      }
    }
  }
  REP(i, w) ans[h] += '#';
  h++;
  REP(i, w) ans[h] += '.';
  h++;
  A--;
  for(int c = 0;B > 0; c++){
    h++;
    if(c & 1){
      REP(i,w) ans[h - 1] += '.'; 
    }else{
      REP(i, w){
        if(i & 1 && B > 0){
          ans[h - 1] += '#';
          B--;
        }else{
          ans[h - 1] += '.';
        }
      }
    }    
  }
  cout << h << ' ' << w << endl;
  REP(i,h){
    cout << ans[i] << endl;
  }
  return 0;
}