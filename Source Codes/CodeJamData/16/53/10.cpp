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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif


struct Test {
  void run(int testid) {


    cout << "Case #" << testid << ": ";
  }
};


#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Test test;
    test.run(i);
  }

  return 0;
}
