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

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int a[111];
int F[111][111];

int f(int i,int j){
    if(j-i<2)return 0;
    int&res=F[i][j];
    if(res<0){
        res=-1u/4;
        for(int k=i+1;k<j;++k)
            res<?=f(i,k)+f(k,j);
        res+=a[j]-a[i]-2;
    }
    return res;
}

void Solve(){
    cin>>n>>m;
    for(int i=0;i<m;++i)cin>>a[i];
    a[m++]=0;
    a[m++]=n+1;
    sort(a,a+m);
    memset(F,-1,sizeof F);
    cout<<f(0,m-1)<<endl;
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
