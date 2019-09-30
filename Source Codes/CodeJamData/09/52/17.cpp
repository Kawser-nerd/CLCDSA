#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
//#include <ext/hash_map>

using namespace std;
//using namespace __gnu_cxx;

#define FOR(i, a, n) for(int i=(a); i<(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define sz(X) int((X).size())
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()

typedef long long lint;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

template<class T> ostream &operator<<(ostream &os, vector<T> vec)
{
    os<<'{';
    REP(i, sz(vec)){
        os<<vec[i];
        if (i+1!=sz(vec)) os<<',';
    }
    os<<'}';
    return os;
}

template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1, T2> par)
{
    os<<'('<<par.X<<','<<par.Y<<')';
    return os;
}

string pol;
string words[110];
int n, k;
int mod=10009;
int ww[110][256];

map<pair<int, string>, int> was;
map<string, int> was1;

int co(string t){
    if(was1.find(t)!=was1.end()) return was1[t];
    int ans=0;
    REP(i, n){
        int ans1=1;
        REP(j, sz(t)){
            ans1=ans1*ww[i][t[j]]%mod;
        }
        ans=(ans+ans1)%mod;
    }
    return was1[t]=ans;
}

int solvepol(int k, string p){
    if(k==0) return sz(p)==0;
    if(was.find(mp(k, p))!=was.end()) return was[mp(k, p)];
    int ans=0;
    REP(i, 1<<sz(p)){
        string q, t;
        REP(j, sz(p)){
            if((i>>j)&1)q+=p[j];
            else t+=p[j];
        }
        ans=(ans+co(t)*solvepol(k-1, q))%mod;
    }
    return was[mp(k, p)]=ans;
}

void solve(int test){
    was.clear();
    was1.clear();
    cin>>pol>>k;
    pol+='+';
    cin>>n;
    REP(i, n){
        cin>>words[i];
        REP(j, 256) ww[i][j]=0;
        REP(j, sz(words[i])){
            ++ww[i][words[i][j]];
        }
    }
    cout<<"Case #"<<test<<":";
    FOR(kk, 1, k+1){
        int ans=0;
        for(int i=0; i<sz(pol);){
            int j=i;
            while(pol[i]!='+') ++i;
            string p=pol.substr(j, i-j);
            ans=(ans+solvepol(kk, p))%mod;
            ++i;
        }
        cout<<" "<<ans;
    }
    cout<<endl;
}

int main()
{
    freopen("1.in", "r",stdin);
    freopen("1.out", "w",stdout);
    int n;
    cin>>n;
    REP(test, n) solve(test+1);
    return 0;
}
