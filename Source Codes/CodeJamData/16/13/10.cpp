#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LD long double
#define LL long long
#define int LL
#define FI first
#define SE second
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "[";
  for (auto& tt : V) { os << tt << ","; }
  os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

struct Sol{
  int n;
  vector<int> t;
  vector<vector<int>> d;
  int IL = 0;
  int dfs(int nr,int oj){
    int res = 1;
    for(int el:d[nr]){
      if(el != oj){
        maxi(res,dfs(el,nr) + 1);
      }
    }
    return res;
  }
  int cykl(int nr,int kt){
    if(nr == kt)return 1;
    for(int el:d[nr]){
      int pom = cykl(el,kt);
      if(pom)return pom+1;
    }
    return 0;
  }
  void go(int cas){
    cout << "Case #" << cas << ": ";
    cin >> n;
    t.resize(n+5);
    d.resize(n+5);
    R(i,n){
      cin >> t[i];
      t[i]--;
      d[t[i]].PB(i);
    }
    int res1 = 0,res2 = 0;
    R(i,n){
      if(t[t[i]] == i){
        res1 += dfs(i,t[i]);
      }
      maxi(res2,cykl(i,t[i]));
    }
  //  debug(res1,res2);
    cout << max(res1,res2) << endl;
  }
};


#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  int t;  
  cin >> t;
  R(i,t){
    Sol sol;
    sol.go(i+1);
  }
}
