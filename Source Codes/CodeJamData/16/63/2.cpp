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

const LD kEps = 1E-9;

const int MaxSiz = 1e6 + 5;

vector<int> divisors[MaxSiz];
int nxtPrime[MaxSiz], moebius[MaxSiz];

vector<int> factor(int x) {
  vector<int> result;
  while (x > 1) {
    int p = nxtPrime[x];
    result.push_back(p);
    x /= p;
  }
  return result;
}

void preproc() {
  for (int i = 1; i < MaxSiz; i++) {
    for (int j = i; j < MaxSiz; j += i) { divisors[j].push_back(i); }
  }

  iota(nxtPrime, nxtPrime + MaxSiz, 0);
  for (int p = 2; p < MaxSiz; p++) {
    if (nxtPrime[p] != p) { continue; }
    for (int i = p * 2; i < MaxSiz; i += p) {
      if (nxtPrime[i] == i) { nxtPrime[i] = p; }
    }
  }

  for (int i = 1; i < MaxSiz; i++) {
    auto F = factor(i);
    moebius[i] = 1;
    for (int j = 0; j < SZ(F) - 1; j++) {
      if (F[j] == F[j + 1]) { moebius[i] = 0; }
    }

    for (int v : F) { moebius[i] = -moebius[i]; }
  }
}

struct Test {
  int N;
  int R;


  set<pair<LD, LD>> taken;

  void run(int testid) {
    cin >> N >> R;

    int result = 2;

    for (int x = 1; x < min((int)1.01e6, N); x++) {
      LD ty = (1E12 / (LD)(R * R) - x * x);
      if (ty < kEps) { break; }
      ty = sqrt(ty);

      debug(x, ty);

      int maxY = (int)floor(ty - kEps);
      for (int i = 0; i < 4; i++) {
        maxY++;
        double tt = (double)R * R * (double)(x * x + maxY * maxY);
        bool ok = false;
        if (tt < 1e13) {
          if (R * R * (x * x + maxY * maxY) < (int)1e12) {
            ok = true;
          }
        }

        if (!ok) { maxY--; }

      }

      mini(maxY, N - 1);
      if (maxY <= 0) { break; }

      debug(x, maxY);

      int numOk = 0;
      for (int d : divisors[x]) {
        debug(d, moebius[d]);
        numOk += moebius[d] * (maxY / d);
      }
      debug(x, numOk);
      result += numOk;
    }


    cout << "Case #" << testid << ": " << result << "\n";
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
  debug("done");

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Test test;
    test.run(i);
  }

  return 0;
}
