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

typedef long long ll;

using namespace std;

const int Mod = 1000000007;

int s[1111111];

int Add(int x,int y){
    for(x+=555555;x;x/=2)s[x]=(s[x]+y)%Mod;
}

int Sum(int x,int y){
    if(x>y)return 0;
    int res=0;
    for(x+=555555,y+=555555;x<=y;x=(x+1)/2,y=(y-1)/2){
        if(x&1)res=(res+s[x])%Mod;
        if(~y&1)res=(res+s[y])%Mod;
    }
    return res;
}

ll A[111],X,Y,Z;
int a[555555],n,m;
int f[555555],x[555555];

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int tc=0,T;
    for(cin>>T;tc++<T;){
        int res=0;
        cin>>n>>m>>X>>Y>>Z;
        for(int i=0;i<m;++i)cin>>A[i];
        for(int i=0;i<n;++i){
            a[i]=A[i%m];
            x[i]=a[i];
            A[i%m]=(X*A[i%m]+Y*(i+1))%Z;
        }
        sort(x,x+n);
        memset(s,0,sizeof s);
        memset(f,0,sizeof f);
        for(int i=n-1;i>=0;--i){
            int j=upper_bound(x,x+n,a[i])-x;
            f[i]=(1+Sum(j,n-1))%Mod;
            res=(res+f[i])%Mod;
            Add(lower_bound(x,x+n,a[i])-x,f[i]);
        }
        printf("Case #%d: %d\n",tc,res);
    }
    return 0;
}
