#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
#define MAX 51
struct Sol{

string c;


int t[MAX][MAX];
int d[MAX];
map<PII,int> pam;
int gdc[MAX];
void init(){
  R(i,MAX){
    d[i] = 0;
    gdc[i] = 0;
    R(j,MAX)t[i][j] = 0;
  }
}
void add_edge(int a,int b){
  if(!(c[a] <= '9' && c[a] >= '0')){
    debug("add_edge",a,b);
    t[a][b] = 1;
  }
}

int gd = 0;
void licz(){
  if(c[gd] == ')' || c[gd] == '|')return;
  if(c[gd] == '('){
    int beg = gd;
    vector<int> kon;
    while(c[gd] != ')'){
      gd++;
      licz();
      if(c[gd] == ')' || c[gd] == '|'){
        kon.PB(gd);
      }else{
        gd--;
      }
    }
    debug(kon);
    R(i,SZ(kon)-1){
      add_edge(beg,kon[i]+1);
      add_edge(kon[i],kon.back());
    }
    gd++;
    if(c[gd] == '*'){
      add_edge(beg,gd);
      add_edge(gd,beg);
      gd++;
    }
  }else{
    debug("cyferka", gd);
    assert(c[gd] <= '9' && c[gd] >= '0');
    gd++;
  }
}

void wys(int a){
// #warning usunac 
//   for(int i=0;i<n+1;i++){
//     if((a >> i)&1)cerr << i << ", ";
//   }
//   cerr << "\n";
}

int nast(int mb,int x){
 // debug("nast", x);
 // wys(x);
  mb &= gdc[x];
  int res = 0;
  while(mb){
    int pom = __builtin_ctzll(mb);
    mb -= 1ll << pom;
    res |= d[pom];
  }
 // debug(res);
  return res;
}
int n;
int cok(int mb,int dl){
  //debug("cok",dl);
 // wys(mb);
  if(dl == 0){
    return (mb >> n) & 1;
  }
  auto xx = pam.find(MP(mb,dl));
  if(xx != pam.end())return xx->SE;
  int &res = pam[MP(mb,dl)];
  R(i,10){
    res += cok(nast(mb,i), dl-1);
  }
 // debug("end cok", mb,dl);
  return res;
}


int go2(int x,int dl,int p10,int mb){
  debug("go2", x, dl, p10, mb);
  if(dl == -1){
    return (mb >> n) & 1;   
  }
  int res = 0;
  R(i,x/p10){
    res += cok(nast(mb,i), dl);
  }
  res += go2(x%p10,dl-1,p10/10,nast(mb,x/p10));
  wys(mb);
  debug(dl,p10,res);
  return res;
}
int go(int x){
  if(x==0)return 0;
  __int128_t p10 = 1;
  int dl = 0;
  int res = 0;
  while(p10*10 <= x){
    for(int i = 1; i < 10; i++){
      res += cok(nast(d[0],i), dl);
    }
    p10 *= 10;
    dl++;
  }
  debug("pol go", res, (int)p10, dl);
 // debug("xxx",(int)(p10));
  for(int i=1;i<x/p10;i++){
    res += cok(nast(d[0],i), dl);
  }
  res += go2(x%p10, dl-1, p10/10, nast(d[0],x/p10));
  debug("go", x,res);
  return res;
}

void run(int cas){
  init();
  cout << "Case #" << cas << ": ";
  int a,b;
  cin >> a >> b >> c;
  n = SZ(c)+1;
  c = '0' + c + '0';
  R(i,n){
    if(c[i] != '|')
      add_edge(i,i+1);
  }
  while(gd!=n){
    //if(gd == 15)exit(1);
    debug("tu", gd);
    licz();
  }
  debug("mam graf",n);
  R(i,n+1)R(j,n+1)R(k,n+1)if(t[j][i] && t[i][k])t[j][k] = 1;
  R(i,n+1)t[i][i] = 1;
  R(i,n){
    if(c[i] <= '9' && c[i] >= '0'){
      gdc[c[i]-'0'] |= 1ll << i;
      R(j,n+1){
        if(t[i+1][j] && (c[j] <= '9' && c[j] >= '0'))
          d[i] |= 1ll<<j;
      }
    }
    R(j,n+1){
      if((d[i] >> j) & 1)
        cerr << i << "->" << j << "\n"; 
    }
  }
  debug("mam drugi");
  cout << go(b) - go(a-1) << endl;
}

};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;cin >> t;
  for(int i=1;i<=t;i++){
    Sol sol;
    sol.run(i);
  }
}
