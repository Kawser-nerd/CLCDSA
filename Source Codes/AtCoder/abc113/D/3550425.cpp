#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<ll> vll;
typedef std::vector<std::vector<ll> > vvll;
inline void scan(int&a){scanf("%d",&a);}
inline void scan(int&a,int&b){scanf("%d%d",&a,&b);}
inline void scan(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void print(int a){printf("%d\n",a);}
inline void print(ll a){printf("%lld\n",a);}
using namespace std;

int mod = 1000000007;
ll po(ll k, ll x) {
  if (x == 0) {
    return 1;
  }
  if (x == 1) {
    return k % mod;
  }
  ll y = po(k, x/2);
  y = y * y % mod;
  if (x % 2 == 1) {
    y = y * k % mod;
  }
  return y;
}
auto berlekamp_massey(vll & s) {
  int N = s.size();
  vll C(N, 0);
  C[0] = 1;
  vll B(N, 0);
  B[0] = 1;
  int L = 0;
  int m = 1;
  ll b = 1;
  rep (n, N) {
    ll d = s[n];
    FOR (i, 1, L+1) {
      d = (d + C[i] * s[n-i]) % mod;
    }
    if (d == 0) {
      m = m + 1;
    } else if (2 * L <= n) {
      auto T = C;
      rep (i, N) {
        ll dec = d * po(b, mod-2) % mod * B[(i-m + N) % N] % mod;
        C[i] = (C[i] - dec + mod) % mod;
      }
      L = n + 1 - L;
      swap(B, T);
      b = d;
      m = 1;
    } else {
      rep (i, N) {
        ll dec = d * po(b, mod-2) % mod * B[(i-m + N) % N] % mod;
        C[i] = (C[i] - dec + mod) % mod;
      }
      m = m + 1;
    }
  }
  return make_tuple(L, C);
}

auto berlekamp_massey_vec2(vvll & b) {
  int N = b.size();
  int deg = b[0].size();
  std::random_device rnd;
  std::mt19937 mt(rnd());
  vll u(deg);
  rep (i, deg) {
    u[i] = mt();
  }
  vll s(N, 0);
  rep (i, N) {
    rep (j, deg) {
      s[i] = (s[i] + b[i][j] * u[j]) % mod;
    }
  }
  return berlekamp_massey(s);
}

int h, w, k;
vvll A;
// O(w)
vll A_(vll bi) {
  vll ret(w, 0);
  rep (i, w) {
    FOR (j, max(i-1,0), min(i+2,w)) {
      ret[i] = (ret[i] + A[i][j] * bi[j]) % mod;
    }
  }
  return ret;
}

int L;
vll C, v0;
vll calc_r(ll a) {
  if (a == 0) {
    return v0;
  }
  vll x = calc_r(a/2);
  vll d(L*2, 0);
  rep (i, L) {
    rep (j, L) {
      int ind = i + j + (a&1);
      d[ind] = (d[ind] + x[i]*x[j]) % mod;
    }
  }
  for (int i = L*2-1; i >= L; --i) {
    FOR (j, 1, L+1) {
      d[i-j] = (d[i-j] + (d[i] * (mod - C[j]))) % mod;
    }
  }
  d.resize(L);
  return d;
}

int main() {
  scan(h, w, k);
  if (w == 1) {
    print(1);
    return 0;
  }
  vll b(w, 0);
  b[0] = 1;

  vll swaps(w, 1);
  FOR (i, 2, w) {
    swaps[i] = (swaps[i-1] + swaps[i-2]) % mod;
  }
  A.assign(w, vll(w, 0));
  rep (i, w) {
    int j = i-1;
    if (j >= 0) {
      A[i][j] = swaps[i-1] * swaps[w-i-1] % mod;
    }
    j = i;
    A[i][j] = swaps[i] * swaps[w-i-1] % mod;
    j = i+1;
    if (j < w) {
      A[i][j] = swaps[i] * swaps[w-i-2] % mod;
    }
  }

  vvll Ab(2*w+1);
  Ab[0] = b;
  rep (i, 2*w) {
    Ab[i+1] = A_(Ab[i]);
  }
  if (h <= 2*w) {
    print(Ab[h][k-1]);
    return 0;
  }

  tie(L, C) = berlekamp_massey_vec2(Ab);
  C.resize(L+1);
  v0.assign(L, 0);
  v0[0] = 1;

  auto ans_cf = calc_r(h);
  ll ans = 0;
  rep (i, L) {
    ans = (ans + ans_cf[i] * Ab[i][k-1]) % mod;
  }
  print(ans);

  return 0;
}