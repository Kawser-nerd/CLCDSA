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

PDD p[1100000];
PDD p1[1100000];

struct mycmp{
    bool operator()(PDD x, PDD y) const{
        swap(x.X, x.Y);
        swap(y.X, y.Y);
        return x<y;
    }
};

template<class T> T sqr(T x){
    return x*x;
}

double dist(PDD a, PDD b){
    return sqrt(sqr(a.X-b.X)+sqr(a.Y-b.Y));
}

double tri(PDD a, PDD b, PDD c){
    return dist(a, b)+dist(b, c)+dist(c, a);
}

void solve(int test){
//write code here
    int n;
    cin>>n;
    REP(i, n){
        cin>>p[i].X>>p[i].Y;
    }
//    double ans=1e100;
//    REP(i, n){
//        FOR(j, i+1, n){
//            FOR(k, j+1, n){
//                ans=min(ans, tri(p[i], p[j], p[k]));
//            }
//        }
//    }
    sort(p, p+n);
    double ans=1e100;
    int o1=0;
    set<PDD, mycmp> o;
    REP(i, n){
        o.insert(p[i]);
        while(o1<i && abs(p[o1].X-p[i].X)>=ans/2){
            o.erase(p[o1]);
            ++o1;
        }
        set<PDD, mycmp>::iterator it, it1;
        it=o.lower_bound(mp(p[i].X, p[i].Y-ans/2));
        it1=o.lower_bound(mp(p[i].X, p[i].Y+ans/2));

        int k=0;
        for(; it!=it1; ++it){
            if(*it!=p[i])p1[k++]=*it;
        }
        REP(j, k){
            FOR(t, j+1, k){
                double ans1=tri(p[i], p1[j], p1[t]);
                ans=min(ans, ans1);
            }
        }
    }
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
