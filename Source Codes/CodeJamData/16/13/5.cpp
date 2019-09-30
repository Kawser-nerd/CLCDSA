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
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}

template<class TH> void _dbg(const char* sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char* sdbg, TH h, TA... t){
  while(*sdbg!=',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif


struct Test {
  vector<int> nextElem;
  vector<vector<int>> prevAdj;
  vector<bool> visited, nvis;
  int N;
  int sumTwo, maxMore;

  int getPath(int v) {
    visited[v] = true;
    int result = 1;
    for (int s : prevAdj[v]) {
      if (!visited[s]) {
        maxi(result, getPath(s) + 1);
      }
    }

    return result;
  }

  void process(int v) {
    nvis = vector<bool>(N + 1);
    vector<int> cycle;
    int s = v;
    do {
      nvis[s] = true;
      cycle.push_back(s);
      s = nextElem[s];
    } while (!nvis[s]);
    
    if (s != v) { return; }

    for (int t : cycle) { visited[t] = true; }

    if (SZ(cycle) > 2) {
      maxi(maxMore, SZ(cycle));
      return;
    }

    assert(SZ(cycle) == 2);
    sumTwo += getPath(cycle[0]) + getPath(cycle[1]);

  }

  void run(int testid) {
    cin >> N;
    nextElem.resize(N + 1);
    visited.resize(N + 1);
    prevAdj.resize(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> nextElem[i];
      prevAdj[nextElem[i]].push_back(i);
    }

    sumTwo = maxMore = 0;
    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        process(i);
      }
    }

    cout << "Case #" << testid << ": ";

    cout << max(sumTwo, maxMore) << "\n";
  }
};

#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Test test;
    test.run(i);
  }

  return 0;
}
