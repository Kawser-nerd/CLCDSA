#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tr1/unordered_map>
#include <utility>
#include <vector>

using namespace std;
using namespace std::tr1;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )
typedef long long int64;
template <typename T> inline int get_bit(const T &x, int index) {
  return (int)((x >> index) & 1);
}
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )
#define debug(x) cerr << #x << " = " << (x) << endl;

typedef vector<int> Kombinacija;
typedef vector<pair<Kombinacija, int64> > BazenKombinacija;
typedef unordered_map<int64, int> ProduktMapa;

int64 fakt(int n) {
  int64 ans = 1;
  for (int i=2; i<=n; ++i) {
    ans *= i;
  }
  return ans;
}

int64 calc_weight(const Kombinacija &komb) {
  int n = komb.size();
  map<int, int> cnts;
  for (int i=0; i<n; ++i) {
    ++cnts[komb[i]];
  }

  int64 ans = fakt(n);
  foreach (it, cnts) {
    ans /= fakt(it->second);
  }
  return ans;
}

void rekkomb(int N, int M, int mini, Kombinacija &sofar, vector<pair<Kombinacija, int64> > &sve) {
  if (N == 0) {
    sve.push_back(make_pair(sofar, calc_weight(sofar)));
    return;
  }

  for (int x=mini; x<=M; ++x) {
    sofar.push_back(x);
    rekkomb(N-1, M, x, sofar, sve);
    sofar.pop_back();
  }
}

BazenKombinacija genkomb(int N, int M) {
  Kombinacija tmp;
  BazenKombinacija sve;
  rekkomb(N, M, 2, tmp, sve);
  return sve;
}

void genprodukti(const Kombinacija &komb, ProduktMapa &M) {
  int N = komb.size();
  for (int m=0; m<(1<<N); ++m) {
    int64 P = 1;
    for (int i=0; i<(int)komb.size(); ++i) {
      if (get_bit(m, i)) {
        P *= komb[i];
      }
    }
    ++M[P];
  }
}

void solve1() {
  int R, N, M, K;
  cin >> R >> N >> M >> K;

  BazenKombinacija komb = genkomb(N, M);
  vector<ProduktMapa > produkti(komb.size());
  for (int i=0; i<(int)komb.size(); ++i) {
    genprodukti(komb[i].first, produkti[i]);
  }

  repeat (R) {
    vector<long double> vj(komb.size(), 1);
    repeat (K) {
      int p;
      cin >> p;
      for (int i=0; i<(int)komb.size(); ++i) {
        if (vj[i] == 0) {
          continue;
        }
        ProduktMapa::iterator it = produkti[i].find(p);
        if (it == produkti[i].end()) {
          vj[i] = 0;
        } else {
          vj[i] *= it->second;
        }
      }
    }

    int besti = 0;
    long double bestp = -1;
    
    for (int i=0; i<(int)komb.size(); ++i) {
      long double p = komb[i].second * vj[i];
      if (p > bestp) {
        bestp = p;
        besti = i;
      }
      assert(p >= 0);
    }

    const Kombinacija &k = komb[besti].first;
    for (int i=0; i<N; ++i) {
      cout << k[i];
    }
    cout << '\n';
  }
}

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    cout << "Case #" << tt << ":\n";
    solve1();
  }
  
  return 0;
}
