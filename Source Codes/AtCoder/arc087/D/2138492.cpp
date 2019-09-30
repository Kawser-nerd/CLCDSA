/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-26 20:57:11
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

const int MAX_SIZE = 1000010;
const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init() {
  inv[1] = 1;
  for (int i=2; i<MAX_SIZE; i++) {
    inv[i] = ((MOD - inv[MOD%i]) * (MOD/i))%MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<MAX_SIZE; i++) {
    fact[i] = (i * fact[i-1])%MOD;
    factinv[i] = (inv[i] * factinv[i-1])%MOD;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%MOD * factinv[n-k])%MOD;
  }
  return 0;
}

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

int N;
vector<int> V[5010];
vector<int> children[5010];
int child_num[5010];
int parent[5010];
ll DP[5010][5010];

int calc_child_num(int n)
{
  if (child_num[n] >= 0)
    return child_num[n];
  child_num[n] = 1;
  for (auto x : children[n])
  {
    child_num[n] += calc_child_num(x);
  }
  return child_num[n];
}

int main()
{
  init();
  cin >> N;
  for (auto i = 0; i < N-1; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  queue<int> Q;
  Q.push(0);
  fill(child_num, child_num + 5010, -1);
  fill(parent, parent + 5010, -1);
  parent[0] = -2;
  while (!Q.empty())
  {
    int now = Q.front();
    Q.pop();
    for (auto x : V[now])
    {
      if (parent[x] == -1)
      {
        parent[x] = now;
        children[now].push_back(x);
        Q.push(x);
      }
    }
  }
  calc_child_num(0);
  bool is_there_two_center = false;
  int center = 0;
  while (true)
  {
    bool found_center = true;
#if DEBUG == 1
    cerr << "center = " << center << endl;
#endif
    for (auto x : children[center])
    {
      if (N % 2 == 0 && child_num[x] == N / 2)
      {
        is_there_two_center = true;
        center = x;
        break;
      }
      else if (child_num[x] > N/2)
      {
        center = x;
        found_center = false;
        break;
      }
    }
    if (found_center)
      break;
  }
  if (is_there_two_center)
  {
    ll sq = fact[N / 2];
    cout << (sq * sq) % MOD << endl;
    return 0;
  }
  vector<ll> T;
  T.push_back(0);
  ll nokori = N-1;
  for (auto x : children[center])
  {
    ll n = child_num[x];
    T.push_back(n);
    nokori -= n;
  }
  if (nokori > 0)
    T.push_back(nokori);
  int X = T.size();
  X--;
#if DEBUG == 1
  cerr << "T : ";
  for (auto x : T)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
  fill(&DP[0][0], &DP[0][0] + 5010 * 5010, 0);
  DP[0][0] = 1;
  for (auto x = 1; x <= X; x++)
  {
    for (auto i = 0; i <= T[x]; i++)
    {
      for (auto k = 0; k <= N-i; k++)
      {
        ll c = C(T[x], i);
        ll plus = (DP[x - 1][k] * fact[i]) % MOD;
        plus = (plus * ((c * c) % MOD)) % MOD;
#if DEBUG == 1
        cerr << "x = " << x << ", i = " << i << ", k = " << k << endl;
        cerr << "DP[" << k + i << "][" << x << "] += " << plus << endl;
#endif
        DP[x][k + i] += plus;
        DP[x][k + i] %= MOD;
      }
    }
  }
  ll ans = 0;
#if DEBUG == 1
  for (auto x = 1; x <= X; x++)
  {
    for (auto k = 0; k <= N; k++)
    {
      cerr << "DP[" << x << "][" << k << "] = " << DP[x][k] << endl;
    }
  }
#endif

  for (auto k = 0; k <= N; k++)
  {
    if (k%2 == 0)
    {
      ans += (fact[N - k] * DP[X][k]) % MOD;
      ans %= MOD;
    }
    else
    {
      ans += MOD - (fact[N - k] * DP[X][k]) % MOD;
      ans %= MOD;
    }
  }
  cout << ans << endl;
}