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
  int n;
  cin >> n;
  int a[100005];
  int maxa = 0, maxi;
  REP(i,n){
    cin >> a[i];
    if(a[i] > maxa){
      maxa = a[i];
      maxi = i;
    }
  }
  double diff = INF;
  int pairi;
  REP(i,n){
    if(i == maxi) continue;
    if(abs(maxa / 2.0 - a[i]) < diff){
      diff = abs(maxa / 2.0 - a[i]);
      pairi = i;
    }
  }
  cout << a[maxi] << ' ' << a[pairi] << endl;
  return 0;
}