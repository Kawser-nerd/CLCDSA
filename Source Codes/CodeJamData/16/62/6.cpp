#include<stdio.h>
int tc,tcn;
int n,x;
long long int ans;
long long int mod=1000000007;
long long int ift[10001000];
long long int mpow(long long int x,long long int y){
    if(y==0)return 1;
    if(y%2==1)return mpow(x,y-1)*x%mod;
    long long int t=mpow(x,y/2);
    return t*t%mod;
}
long long int f(int x){
    int i;
    long long int res=0;
    for(i=0;i<=x;i++){
        if(i%2==0)res+=ift[i];
        else res+=mod-ift[i];
        res%=mod;
    }
    return res;
}
int main(){
    int i,j,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&tcn);
    n=10000010;
    ift[0]=1;
    for(i=1;i<=n;i++){
        ift[i]=ift[i-1]*i%mod;
    }
    ift[n]=mpow(ift[n],mod-2);
    for(i=n;i>0;i--){
        ift[i-1]=ift[i]*i%mod;
    }
    for(tc=1;tc<=tcn;tc++){
        scanf("%d%d",&n,&x);
        ans=f(x-1)*f(n-x)%mod;
        ans=mod-ans+1;
        ans%=mod;
        printf("Case #%d: %lld\n",tc,ans);
    }
    return 0;
}
