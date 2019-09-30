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
#include<unordered_set>
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
#define DEB(X) cout << /*#X <<":" <<*/X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e9;
// typedef std::pair<int,int> P;
struct edge {int to,cost;};
#define VMAX 100000

ll N,K,ans=0;
ll X[100010],Y[100010];
ll W[3001][3001],B[3001][3001];
char C[100010];
//yxyx
ll imos(int a,int b,int c,int d,int mode){
    int res=0;
    if(a>c||b>d)return 0;
        if(mode==0){
             if((0<=c&&c<2*K)&&(0<=d&&d<2*K))res+=W[c][d];
             if((0<=c&&c<2*K)&&(0<=b-1&&b-1<2*K))res-=W[c][b-1];
             if((0<=a-1&&a-1<2*K)&&(0<=d&&d<2*K))res-=W[a-1][d];
             if((0<=a-1&&a-1<2*K)&&(0<=b-1&&b-1<2*K))res+=W[a-1][b-1];
        }else{
            if((0<=c&&c<2*K)||(0<=d&&d<2*K))res+=B[c][d];
            if((0<=c&&c<2*K)||(0<=b-1&&b-1<2*K))res-=B[c][b-1];
            if((0<=a-1&&a-1<2*K)||(0<=d&&d<2*K))res-=B[a-1][d];
            if((0<=a-1&&a-1<2*K)||(0<=b-1&&b-1<2*K))res+=B[a-1][b-1];
        }
        return res;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin>>N>>K;
    REP(i,N){
        cin>>X[i]>>Y[i]>>C[i];
        X[i]%=2*K,Y[i]%=2*K;
        if(C[i]=='W')W[Y[i]][X[i]]+=1;
        else B[Y[i]][X[i]]+=1;
    }
    REP(i,2*K)REP(j,2*K){
        W[i][j+1]+=W[i][j];
        B[i][j+1]+=B[i][j];
    }
    REP(i,2*K)REP(j,2*K){
        W[i+1][j]+=W[i][j];
        B[i+1][j]+=B[i][j];
    }
    REP(i,2*K){REP(j,2*K){
        DEB(B[K-1-i][j])
    }END}
    REP(i,K)REP(j,K)REP(k,2){
      ll tans=0;
        tans+=imos(0,0,i-1,j-1,(k==0?0:1));
        tans+=imos(0,j,i-1,j+K-1,(k!=0?0:1));
        tans+=imos(0,j+K,i-1,2*K-1,(k==0?0:1));
        tans+=imos(i,0,i+K-1,j-1,(k!=0?0:1));
        tans+=imos(i,j,i+K-1,j+K-1,(k==0?0:1));
        tans+=imos(i,j+K,i+K-1,2*K-1,(k!=0?0:1));
        tans+=imos(K+i,0,2*K-1,j-1,(k==0?0:1));
        tans+=imos(K+i,j,2*K-1,j+K-1,(k!=0?0:1));
        tans+=imos(K+i,j+K,2*K-1,2*K-1,(k==0?0:1));
        ans=max(tans,ans);
    }

    cout<<ans<<endl;
    return 0;
}