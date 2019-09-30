#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LL long long
#define int LL
#define st first
#define nd second
#define FI st
#define SE nd
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i, n) FOR(i, 0, (int)(n)-1)
#define R(i,n) REP(i,n)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>
template<class C4> void mini(C4&a4, C4 b4){a4=min(a4,b4);}
template<class C4> void maxi(C4&a4, C4 b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char* sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char* sdbg, TH h, TA... t){
  while(*sdbg!=',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

template<class L, class R> ostream& operator<<(ostream& os, pair<L, R> pr) {
  return os << "(" << pr.first << ", " << pr.second << ")";
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for(auto vv : V) os << vv << ","; return os << "]";
}

using LD = long double;

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif


const int Mod = 1e9 + 7;
const int MaxN = 1e7 + 5;

const int SmallN = 1e4 + 5;

int facts[MaxN], invFacts[MaxN];
int possPref[MaxN], possB[MaxN];

int powMod(int a, int n) {
  assert(a < Mod);
  int res = 1;
  while (n) {
    if (n & 1) { res = ((LL)res * a) % Mod; }
    n >>= 1;
    a = ((LL)a * a) % Mod;
  }
  return res;
}

int mulMod(int a, int b) {
  assert(a < Mod);
  assert(b < Mod);
  return ((LL)a * b) % Mod;
}

void preproc() {
  facts[0] = 1;
  for (int i = 1; i < MaxN; i++) {
    facts[i] = (mulMod((LL)facts[i - 1], i)) % Mod;
  }
  
  invFacts[MaxN - 1] = powMod(facts[MaxN - 1], Mod - 2);
  for (int i = MaxN - 2; i >= 0; i--) {
    invFacts[i] = ((LL)invFacts[i + 1] * (i + 1)) % Mod;
  }

  possB[0] = 1;
  possB[1] = 0;
  possPref[0] = possPref[1] = 1;

  for (int n = 2; n < MaxN; n++) {
    int a = powMod(n, Mod - 2);
    LL x = ((LL)a * possPref[n - 2]) % Mod;
    possB[n] = x;
    possPref[n] = (possPref[n - 1] + x) % Mod;
  }
}

int newton(int N, int K) {
  if (N < 0 || K < 0 || K > N) { return 0; }
  int res = facts[N];
  res = ((LL)res * invFacts[K]) % Mod;
  res = mulMod(res, invFacts[N - K]);
  return res;
}

struct Test {
  int N, K;

  void run(int testid) {
    cin >> N >> K;

    int result = 1;
    result = possB[K - 1];
    result = ((LL)result * possB[N - K]) % Mod;
    cout << "Case #" << testid << ": " << (Mod + 1 - result) % Mod << "\n";
  }
};


#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  preproc();
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Test test;
    test.run(i);
  }

  return 0;
}
