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
  ll N, S;
  cin >> N >> S;
  if(N < S){
    cout << -1 << endl;
    return 0;
  }else if(N == S){
    cout << N + 1 << endl;
    return 0;
  }
  for(int b = 2; b <= (int)sqrt(N); b++){
    ll ans = 0;
    ll temp_N = N;
    while(temp_N >= b){
      ans += temp_N % b;
      temp_N /= b;
    }
    ans += temp_N;
    if(ans == S){
      cout << b << endl;
      return 0;
    }
  }
  int maxp = (sqrt(N) == floor(sqrt(N))) ? sqrt(N) - 1 : sqrt(N);
  for(int p = maxp; p >= 1; p--){
    ll b = (N - S) / p + 1;
    if(b > 1 && N / b + N % b == S){
      cout << b << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}