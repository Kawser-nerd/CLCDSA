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

const int MAX_N = 1e5 * 2 + 2;
ll ifact[MAX_N];
ll fact[MAX_N];

ll mod_pow(ll n, ll x){
  ll res = 1;
  while(n > 0){
    if(n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

void inv_fact(int M){
  fact[0] = ifact[0] = 1;
  for(int i = 1; i <= M; i++){
    fact[i] = fact[i-1] * i % MOD;
  }
  ifact[M] = mod_pow(MOD - 2, fact[M]);
  for(int i = M - 1; i >= 1; i--){
    ifact[i] = ifact[i + 1] * (i + 1) % MOD;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  inv_fact(N + K);
  cout << (fact[N + K - 1] * ifact[N - 1]) % MOD * ifact[K] % MOD << endl;
  return 0;
}