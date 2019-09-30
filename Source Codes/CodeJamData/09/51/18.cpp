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

int a[20][20];

int isgood(VI v){
    int c[10];
    int n=sz(v)/2;
    REP(i, n) c[i]=i;
    REP(i, n){
        FOR(j, i+1, n){
            if(abs(v[i*2]-v[j*2])+abs(v[i*2+1]-v[j*2+1])==1){
                int p=c[i];
                REP(k, n){
                    if(c[k]==p) c[k]=c[j];
                }
            }
        }
    }
    REP(i, n-1) if(c[i]!=c[i+1]) return 0;
    return 1;
}

int isaccepted(VI v){
    int n=sz(v)/2;
    REP(i, n){
        FOR(j, i+1, n){
            if(abs(v[i*2]-v[j*2])+abs(v[i*2+1]-v[j*2+1])==0){
                return 0;
            }
        }
    }
    return 1;
}

void rearange(VI &v){
//    cout<<"v = "<<v<<endl;
    vector<PII> tmp;
    REP(i, sz(v)/2){
        tmp.pb(mp(v[i*2], v[i*2+1]));
    }
    v.clear();
    sort(all(tmp));
    REP(i, sz(tmp)){
        v.pb(tmp[i].X);
        v.pb(tmp[i].Y);
    }
//    cout<<"v = "<<v<<endl<<endl;
}

void solve(int test){
    map<VI, int> t;
    deque<VI> q;

    int n, m;
    scanf("%d%d", &n, &m);
    VI s, f;
    FOR(i, 1, n+1){
        scanf(" ");
        FOR(j, 1, m+1){
            char c;
            scanf("%c", &c);
            a[i][j] = c=='#';
            if(c == 'o' || c=='w'){
                s.pb(i);
                s.pb(j);
            }
            if(c == 'x' || c=='w'){
                f.pb(i);
                f.pb(j);
            }
        }
    }
    REP(i, n+2){
        REP(j, m+2){
            if(i==0 || j==0 || i==n+1 || j==m+1) a[i][j]=1;
        }
    }

    int whx[]={1, -1, 0, 0};
    int why[]={0, 0, 1, -1};

    t[s]=0;
    q.pb(s);
    while(!q.empty()){
        VI v=q.front();
        q.pop_front();
        int nn=sz(v)/2;
        REP(i, nn){
            REP(j, 4){
                VI v1=v;
                v1[i*2]-=whx[j];
                v1[i*2+1]-=why[j];
//                cout<<v1<<endl;
                if(a[v1[i*2]][v1[i*2+1]]) continue;
                if(!isaccepted(v1)) continue;
                v1[i*2]+=whx[j]*2;
                v1[i*2+1]+=why[j]*2;
                if(a[v1[i*2]][v1[i*2+1]]) continue;
                if(!isaccepted(v1)) continue;
                if(!isgood(v) && !isgood(v1)) continue;
                rearange(v1);
                if(t.find(v1)!=t.end()) continue;
                q.pb(v1);
                t[v1]=t[v]+1;
//                REP(i1, n){
//                    REP(j1, m){
//                        bool f=0;
//                            REP(k, sz(v1)/2){
//                            if(v1[k*2]==i1+1 && v1[k*2+1]==j1+1) f=1;
//                        }
//                        printf("%c", a[i1][j1]? '#': f? 'o': '.');
//                    }
//                    printf("\n");
//                }
//                printf("\n");
//                getchar();
            }
        }
    }

    int ans=t.find(f)==t.end()? -1: t[f];
    cout<<"Case #"<<test<<": "<<ans<<endl;
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
