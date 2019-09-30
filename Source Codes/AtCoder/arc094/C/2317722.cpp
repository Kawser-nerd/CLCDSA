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
int A[100005], B[100005];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  ll ans = 0;
  int Bifmax = INF;
  int eq = 0;
  REP(i,N){
    cin >> A[i] >> B[i];
    ans += A[i];
    if(A[i] > B[i]){
      Bifmax = min(Bifmax, B[i]);
    }else if(A[i] == B[i]){
      eq++;
    }
  }
  if(eq == N) cout << 0 << endl;
  else cout << ans - Bifmax << endl;
  return 0;
}