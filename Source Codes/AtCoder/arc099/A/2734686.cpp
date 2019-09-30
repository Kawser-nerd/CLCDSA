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
  int N, K;
  cin >> N >> K;
  int a[100005], b;
  REP(i,N){
    cin >> a[i];
    if(a[i] == 1) b = i;
  }
  int ans = INF;
  REP(i,N){
    if(i <= b && b < i + K){
      ans = min(ans,
                (i + K - 2) / (K - 1) + (N - (i + K) + K - 2) / (K - 1));
      //      cout << "N, K, i, ans " << N << ' ' << K << ' ' << i << ' ' << (i + K - 2) / (K - 1) << ' ' << (N - (i + K) + K - 2) / (K - 1) << endl;;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}