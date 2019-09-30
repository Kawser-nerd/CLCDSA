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

int n,m,h;
char a[64][64];
int F[64][64][64][64];

int D(int i,int j){
    if(a[i][j]=='#') return 0;
    return 1+D(i+1,j);
}

bool good(int i,int j,int l,int r){
    return a[i+1][j]=='#' && (l<=j && j<=r || a[i][j]=='.');
}

int DD(int i,int j){
    return 1+D(i+1,j);
}

int f(int i,int j,int l,int r){
    if(i==n-1)return 0;
    int&res=F[i][j][l][r];
    if(res<0){
        res=2222222;
        int L=j,R=j;
        for(;L>0 && good(i,L-1,l,r);--L);
        for(;R<m-1 && good(i,R+1,l,r);++R);
        for(j=L;j<=R;++j){
            for(int d=-1;d<2;d+=2){
                int y=j+d;
                if(y<0 || y>=m)continue;
                if(l<=y && y<=r || a[i][y]=='.'){
                    if(a[i+1][y]=='.'){
                        int z=D(i+1,y);
                        if(z<=h){
                            res<?=f(i+z,y,y,y);
                        }
                    }
                }
            }
        }
        for(j=L;j<=R;++j){
            for(int x=L;x<j;++x){
                int z=DD(i+1,j-1);
                if(z<=h) {
                    if(z==1)res<?=f(i+1,j-1,x,j-1)+(j-x);
                    else res<?=f(i+z,j-1,j-1,j-1)+(j-x);
                }
            }
            for(int x=j+1;x<=R;++x){
                int z=DD(i+1,j+1);
                if(z<=h) {
                    if(z==1)res<?=f(i+1,j+1,j+1,x)+(x-j);
                    else res<?=f(i+z,j+1,j+1,j+1)+(x-j);
                }
            }
        }
    }
    return res;
}

void Solve(){
    cin>>n>>m>>h;
    REP(i,n)cin>>a[i];
    REP(j,m)a[n][j]='#';
    CL(F,-1);
    int res=f(0,0,0,0);
    if(res<1000000)printf("Yes %d\n",res);
    else puts("No");
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
