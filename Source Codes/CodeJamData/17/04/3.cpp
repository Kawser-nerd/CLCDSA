//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}

//end of jonathanirvings' template v3.0.3 (BETA)

class BipartiteGraph
{
  public:
  bool visited[10105];
  int with[10105],m,n;
  vector<int> adj[10105];
  bool matched[10105];
  bool adakiri[10105],adakanan[10105];

  void reset(int _m,int _n)
  {
    m = _m; n = _n;
    for (int i = 0; i < m; ++i) {
      adj[i].clear();
    }
  }
  void addEdge(int a,int b)
  {
    adj[a].push_back(b);
  }
  bool match(int x)
  {
    for (int i = 0; i < adj[x].size(); ++i) {
      int j = adj[x][i];
      if (visited[j]) continue;
      visited[j] = 1;
      if (with[j] == -1 || match(with[j])) 
      {
        with[j] = x;
        return true;
      }
    }
    return false;
  }
  void greedyPreprocessing(void) {
    srand(n);
    for (int i = 0; i < m; ++i) {
      vector<int> available;
      for (int j = 0; j < adj[i].size(); ++j) {
        if (with[adj[i][j]] == -1) {
          available.push_back(adj[i][j]);
        }
      }
      if (available.size() == 0) {
        continue;
      }
      int ambil = available[rand() % available.size()];
      matched[i] = true;
      with[ambil] = i;
    }
  }
  int countMCBM(void)
  {
    int ans = 0;
    memset(with, -1, sizeof(with));
    memset(matched, 0, sizeof(matched));
    greedyPreprocessing();
    for (int i = 0; i < m; ++i)
    {
      if (matched[i]) {
        ++ans;
        continue;
      }
      memset(visited, 0, sizeof(visited));
      if(match(i)) 
      {
        matched[i] = 1;
        ++ans;
      }
    }
    return ans;
  }
  void dfs(int now, set<int> &L, vector<int> &R) 
  {
    L.erase(now);
    for (int i = 0; i < adj[now].size(); ++i) {
      if (with[adj[now][i]] == -1) continue;
      if (visited[with[adj[now][i]]]) continue;
      visited[with[adj[now][i]]] = 1;
      R.push_back(adj[now][i]);
      dfs(with[adj[now][i]], L, R);
    }
  }
  pair<vector<int>,vector<int> > getMVC(void)
  {
    vector<int> L, R;
    set<int> l;
    for (int i = 0; i < m; ++i)
    {
      l.insert(i);
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < m; ++i)
    {
      if (matched[i]) continue;
      visited[i] = true;
      dfs(i, l, R);
    }
    for (set<int>::iterator it=l.begin();it!=l.end();++it)
    {
      L.push_back(*it);
    }
    return make_pair(L, R);
  }
  pair<vector<int>,vector<int> > getMIS(void)
  {
    pair<vector<int>,vector<int> > MVC = getMVC();
    pair<vector<int>,vector<int> > MIS;
    memset(adakiri, 0, sizeof(adakiri));
    memset(adakanan, 0, sizeof(adakanan));
    for (int i = 0; i < MVC.fi.size(); ++i) {
      adakiri[MVC.fi[i]] = 1;
    }
    for (int i = 0; i < m; ++i) {
      if (!adakiri[i]) MIS.first.push_back(i);
    }
    for (int i = 0; i < MVC.se.size(); ++i) {
      adakanan[MVC.se[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
      if (!adakanan[i]) MIS.second.push_back(i);
    }
    return MIS;
  }
};

int T;
int n,m;
string s;
int x,y;
set<int> aa,ab,ba,bb;
char data[105][105];
char data2[105][105];
BipartiteGraph BG;

void push(int x,int y,char c)
{
  if (data2[x][y] == '.') data2[x][y] = c;
  else if (data2[x][y] != c) data2[x][y] = 'o';
}

int main()
{
  scanf("%d",&T);
  REPN(cases,T)
  {
    printf("Case #%d: ",cases);
    scanf("%d %d",&n,&m);
    aa.clear();
    ab.clear();
    ba.clear();
    bb.clear();
    REPN(i,n) REPN(j,n)
    {
      aa.insert(i);
      ab.insert(j);
      ba.insert(i+j);
      bb.insert(i-j);
      data[i][j] = '.';
      data2[i][j] = '.';
    }
    TC(m)
    {
      s = GetString();
      scanf("%d %d",&x,&y);
      data[x][y] = s[0];
      data2[x][y] = s[0];
      if (s != "+")
      {
        aa.erase(x);
        ab.erase(y);
      }
      if (s != "x")
      {
        ba.erase(x+y);
        bb.erase(x-y);
      }
    }
    // VALUE(1);
    for (set<int>::iterator it=aa.begin();it!=aa.end();++it)
    {
      int x = *it;
      int y = *(ab.begin());
      push(x,y,'x');
      ab.erase(y);
    }
    vi satu,dua;
    for (set<int>::iterator it=ba.begin();it!=ba.end();++it) satu.pb(*it);
    for (set<int>::iterator it=bb.begin();it!=bb.end();++it) dua.pb(*it);
    BG.reset(SIZE(satu),SIZE(dua));
    // VALUE(SIZE(ba));
    REP(i,SIZE(satu))
    {
      REP(j,SIZE(dua))
      {
        int x = satu[i];
        int y = dua[j];
        if ((x + y) %2 == 0 && 1 <= (x + y) / 2 && (x + y) / 2 <= n && 1 <= (x - y) / 2 && (x - y) / 2 <= n)
        {
          BG.addEdge(i,j);
          // debug("%d %d %d %d %d %d\n",i,j,x,y,(x+y)/2,(x-y)/2);
        }
      }
    }
    BG.countMCBM();
    // REP(i,SIZE(dua)) VALUE(BG.with[i]);
    REP(i,SIZE(dua)) if(BG.with[i] != -1)
    {
      int x = satu[BG.with[i]];
      int y = dua[i];
      // debug("%d %d\n",x,y);
      push((x+y)/2,(x-y)/2,'+');
    }

    vector<pair<char,pii> > risan;
    REPN(i,n) REPN(j,n) if(data2[i][j] != data[i][j])
    {
      risan.pb(mp(data2[i][j],mp(i,j)));
    }
    int tot = 0;
    REPN(i,n) REPN(j,n)
    {
      if (data2[i][j] == 'o') tot += 2;
      else if (data2[i][j] != '.') ++tot;
    }
    printf("%d %d\n",tot,SIZE(risan));
    REP(i,SIZE(risan)) printf("%c %d %d\n",risan[i].fi,risan[i].se.fi,risan[i].se.se);
  }
  return 0;
}









