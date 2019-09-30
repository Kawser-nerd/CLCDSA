#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include <unordered_set>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using std::cout;
using std::vector;
using std::endl;
using std::cin;
using std::string;
using std::min;
using std::max;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e9;
typedef std::pair<int,int> P;
//struct edge {int to,cost;};
#define VMAX 200+10
    ll N,A[100010];
    ll F[100010];
    ll l,r;
    ll ans;

ll LP(ll x,ll y){
    if(y==0)return 1;
    if(y%2==0)return LP((x*x)%MOD,y/2);
    else return LP(x,y-1)*x%MOD;
}
ll Fact[100010];
ll Com[100010];
void FC(ll x){
    Fact[0]=Com[0]=1;
    ll temp=1;
    EREP(i,x){
        temp=temp*i%MOD;
        Fact[i]=temp;
        Com[i]=LP(temp,MOD-2);
    }
}
ll MC(ll x,ll y){
    if(y==0)return 1;
    if(x<y)return 0;
    return Fact[x]*(Com[y]*Com[x-y]%MOD)%MOD;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin>>N;
    REP(i,100010)F[i]=-1;
    REP(i,N+1){
        cin>>A[i];
        if(F[A[i]]==-1)F[A[i]]=i;
        else{
            l=F[A[i]];
            r=i;
        }
    }
    FC(N+2);
    REP(i,N+1){
        DEB(MC(N+1,i+1))DEB(MC(l+N-r,i))END
    cout<<(MC(N+1,i+1)-MC(l+N-r,i) + MOD)%MOD<<endl;
    }
    return 0;
}