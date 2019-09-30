#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n;
int X[64],Y[64],R[64];

ll check(ll z,double r){
    if(z==0)return 0;
    vi p;
    double x=0,y=0;
    REP(i,n)if(z&1ll<<i)p.pb(i),x+=X[i],y+=Y[i];
    x/=sz(p),y/=sz(p);
    REP(k,100){
        double mr=-1;
        int j=0;
        REP(u,sz(p)){
            int i=p[u];
            double rr=hypot(X[i]-x,Y[i]-y)+R[i];
            if(rr>mr)mr=rr,j=i;
        }
        if(mr<=r+1e-9){
            z=0;
            REP(i,n)
                if(hypot(X[i]-x,Y[i]-y)+R[i]<=r+1e-9)
                    z|=1ll<<i;
            return z;
        }
        double d=(mr-r);
        mr-=R[j];
        double dx=(X[j]-x)/mr,dy=(Y[j]-y)/mr;
        x+=dx*d,y+=dy*d;
    }
    return 0;
}

pair<double,ll> f(ll z){
    if(z==0) return make_pair(0.0,0);
    if((z&z-1)==0){
        for(int i=0;i<n;++i)
            if(z&1ll<<i)
                return make_pair(R[i]+0.,z);
    }
    double l=0,r=8000,res=8000;
    ll rz=0;
    for(;r-l>1e-7;){
        double v=(l+r)/2;
        ll Z=check(z,v);
        if(Z){
            rz=Z;
            res=v;
            r=v;
        }else l=v;
    }
    return make_pair(res,rz);
}

void Solve(){
    cin>>n;
    REP(i,n)cin>>X[i]>>Y[i]>>R[i];
    double res=1e111;
    pair<double,ll> v=f(7);
    REP(k,n)REP(j,k+1)REP(i,j+1){
        ll z=(1ll<<i)|(1ll<<j)|(1ll<<k);
        pair<double,ll> p1=f(z);
        if(p1.X<res){
            z=((1ll<<n)-1)^p1.Y;
            pair<double,ll> p2=f(z);
            res<?=p1.X>?p2.X;
        }
    }
    printf("%.10lf\n",res);
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d: ",a);
    return 0;
}
