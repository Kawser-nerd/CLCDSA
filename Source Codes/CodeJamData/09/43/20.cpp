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

vi a[128];

bool cmp(const vi&a,const vi&b){ return a[0]<b[0]; }

bool CMP(const vi&a,const vi&b){
    REP(i,sz(a))if(a[i]>=b[i]) return false;
    return true;
}

int A[128][128],f[128];
bool b[128];

int n,m;

bool dfs(int x){
    b[x]=true;
    REP(y,n)if(A[x][y] && (f[y]<0 || !b[f[y]] && dfs(f[y])))
        return f[y]=x,true;
    return false;
}

void Solve(){
    cin>>n>>m;
    REP(i,n){
        a[i]=vi(m);
        REP(j,m)scanf("%d",&a[i][j]);
    }
    sort(a,a+n,cmp);
    REP(i,n)REP(j,n)A[i][j]=CMP(a[i],a[j]);
    int res=n;
    CL(f,-1);
    REP(i,n){
        CL(b,0);
        res-=dfs(i);
    }
    cout<<res<<endl;
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
