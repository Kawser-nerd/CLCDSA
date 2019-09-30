#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
// Let's Fight!

typedef long long ll;

const int MAXN = 1010101;
const ll MOD = 1000000007;

int N, X;
ll f[MAXN], g[MAXN];
ll fact[MAXN], ifact[MAXN];

void input()
{
  cin>>N>>X;
}

void calc_fg()
{
  f[0] = 1;
  f[1] = 0;
  g[1] = 1;

  for(int i=2; i<=N; i++)
  {
    ll q = ((ll)i * (i-1)) % MOD;
    f[i] = (g[i-1] * q) % MOD;
    g[i] = (i * f[i-1] + q * g[i-1]) % MOD;
  }
}

ll inv(ll a)
{
  ll p = MOD-2;
  ll cur = a, ans = 1;
  while(p)
  {
    if(p&1LL)
      ans = (ans * cur) % MOD;
    cur = (cur * cur) % MOD;
    p >>= 1;
  }
  return ans;
}

void calc_fact()
{
  fact[0] = 1;
  for(int i=1; i<=N; i++)
    fact[i] = (fact[i-1] * i) % MOD;
  for(int i=0; i<=N; i++)
    ifact[i] = inv(fact[i]);
}

ll acomb(ll n, ll x)
{
  ll up = (fact[n] * fact[n]) % MOD;
  ll down = (ifact[n-x] * ifact[n-x]) % MOD;
  down = (down * ifact[x]) % MOD;
  ll tot = (up * down) % MOD;
  tot = (tot * f[n-x]) % MOD;
  return tot;
}

int main(int argc, char** argv)
{
  IOS;
  int T;
  cin>>T;
  int nT = atoi(argv[1]);
  for(int i=1; i<=nT; i++)
    input();
  calc_fg();
  calc_fact();

  ll ans = 0;
  for(int i=X; i<=N; i++)
  {
    ll diff = acomb(N, i);
    ans += diff;
    ans %= MOD;
  }

  if(ans < 0) ans += MOD;

  cout<<"Case #"<<nT<<": "<<ans<<endl;

	return 0;
}
