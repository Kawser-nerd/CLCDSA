#include<cmath>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<numeric>
#include<iostream>
#include<sstream>
using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(i, a, n) for(int i=(a); i<(n); i++)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";REP(__prv,sz(X)-1)cout<<(X)[__prv]<<",";if(sz(X))cout<<*(X).end();cout<<"}"<<endl;}

template<class T> ostream &operator<<(ostream &os, vector<T> &vec)
{
  os<<'{';
  REP(i, sz(vec)){
    os<<vec[i];
    if (i+1!=sz(vec)) os<<',';
  }
  os<<'}';
  return os;
}

template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1, T2> &par)
{
  os<<'('<<par.X<<','<<par.Y<<')';
  return os;
}

typedef long long lint;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

#define SS stringstream
template<typename T> string tos(T q,int w=0){SS
A;A.flags(ios::fixed);A.precision(w);A<<q;string s;A>>s;return s;}
template<typename T> T sto(string s){SS A(s);T t;A>>t;return t;}
template<typename T> vector<T > s2v(string s){SS A(s);vector<T >
ans;while(A&&!A.eof()){T t;A>>t;ans.pb(t);}return ans;}

template<class T> T sqr(T x){
    return x*x;
}

int dist(PII a, PII b){
    return sqr(a.X-b.X)+sqr(a.Y-b.Y);
}



struct Dinic {
    static const int MaxN = 510;
    static const int MaxE = 510*510;
    static const int INF = 1000000000;

    int n, src, tar, ptr;
    int head[MaxN], vert[MaxE], next[MaxE], cap[MaxE];
    int t[MaxN], q[MaxN], work[MaxN];

    void init(int n, int src, int tar){
        this->n=n;
        this->src=src;
        this->tar=tar;
        memset(head, -1, sizeof(head[0])*n);
        ptr = 0; }

    void addedge(int u, int v, int c1, int c2) {
        vert[ptr] = v, cap[ptr] = c1,
        next[ptr] = head[u], head[u] = (ptr++);
        vert[ptr] = u, cap[ptr] = c2,
        next[ptr] = head[v], head[v] = (ptr++); }

    bool dinic_bfs() {
        memset(t, 255, sizeof(t[0]) * n);
        t[src] = 0;
        int p1 = 0, p2 = 0;
        q[p2++] = src;
        while(p1 < p2) {
            for (int v = q[p1++], i = head[v]; i >= 0; i = next[i])
                if (cap[i] > 0 && t[vert[i]] < 0) {
                    t[vert[i]] = t[v] + 1;
                    q[p2++] = vert[i]; }}
        return t[tar] >= 0; }

    int dinic_dfs(int v, int exp) {
        if (v == tar) return exp;
        for (int &i = work[v]; i >= 0; i = next[i]) {
            int u = vert[i], tmp;
            if (cap[i] > 0 && t[u] == t[v] + 1 &&
                    (tmp = dinic_dfs(u, min(exp, cap[i]) ) ) > 0) {
                cap[i] -= tmp;
                cap[i ^ 1] += tmp;
                return tmp;	}}
        return 0; }

    int dinic_flow() {
        int ans = 0;
        while (dinic_bfs()) {
            memcpy(work, head, sizeof(head[0])*n);
            while (1) {
                int delta = dinic_dfs(src, INF);
                if (delta == 0) break;
                ans += delta; }}
        return ans; }};




PII a[510];
int r[510];
int s[510];
Dinic d;

void solve(int test){
//write code here
    int n;
    cin>>n;
    REP(i, n){
        cin>>a[i].X>>a[i].Y>>r[i]>>s[i];
        r[i]=sqr(r[i]);
    }
    int v=n+2, st=n, fi=n+1;
    d.init(v, st, fi);
    int ans=0;
    REP(i, n){
        if(s[i]>=0){
            ans+=s[i];
            d.addedge(st, i, s[i], 0);
        } else d.addedge(i, fi, -s[i], 0);
        FOR(j, i+1, n){
            int distij=dist(a[i], a[j])<=r[i]? Dinic::INF: 0;
            int distji=dist(a[i], a[j])<=r[j]? Dinic::INF: 0;
            d.addedge(i, j, distij, distji);
        }
    }
    ans-=d.dinic_flow();
    cout<<"Case #"<<test<<":";
    cout<<" "<<ans;
    cout<<endl;
}

int main(){
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    cout<<fixed;
    cout.precision(11);
    int n;
    cin>>n;
    REP(i, n) solve(i+1);
    return 0;
}
