#include<stdio.h>
#include<algorithm>
#define mod 998244353
#define maxn 8200
using namespace std;
typedef long long ll;
int n,m,dp[210][maxn<<1],wn[2][maxn<<1],bh[maxn<<1];
int A[maxn<<1],M,fac[maxn<<1],k,inv[maxn<<1];
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a%mod)
        if(b&1)ans=1ll*ans*a%mod;
    return ans;
}
void init(){
    for(int i=1,p;i<M;i<<=1){
        wn[0][i]=1,p=qpow(3,(mod-1)/(i<<1));
        for(int j=1;j<i;++j)wn[0][i+j]=(ll)wn[0][i+j-1]*p%mod;
        wn[1][i]=1,p=qpow(3,mod-1-(mod-1)/(i<<1));
        for(int j=1;j<i;++j)wn[1][i+j]=(ll)wn[1][i+j-1]*p%mod;
    }
}
void fft(int h[],int len,int flag){
    for(int i=0;i<len;++i)if(i<bh[i])swap(h[i],h[bh[i]]);
    for(int i=1;i<len;i<<=1)
        for(int j=0;j<len;j+=(i<<1))
            for(int k=0;k<i;++k){
                int x=h[j+k],y=(ll)h[j+k+i]*wn[flag][i+k]%mod;
                h[j+k]=(x+y)%mod,h[j+k+i]=(x-y+mod)%mod;
            }
    if(flag==1){
        int iv=qpow(len,mod-2);
        for(int i=0;i<len;++i)h[i]=1ll*h[i]*iv%mod;
    }
}
int C(int x,int y){
    if(x>y||x<0)return 0;
    return (ll)fac[y]*inv[x]%mod*inv[y-x]%mod;
}
int main(){
    scanf("%d%d",&n,&m),M=1,k=0,fac[0]=inv[0]=1;
    while(M<2*n)M<<=1,k++;
    for(int i=1;i<=n+2;++i)fac[i]=1ll*fac[i-1]*i%mod;
    inv[n+2]=qpow(fac[n+2],mod-2);
    for(int i=n+1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=0;i<M;++i)bh[i]=(bh[i>>1]>>1)|((i&1)<<(k-1));
    init();
    dp[0][0]=1;
    for(int i=0;i<m;++i){
        for(int j=0;j<=n;++j)
            dp[i+1][j]=(ll)(j*(j+1)/2+1)*dp[i][j]%mod,
            dp[i][j]=(ll)dp[i][j]*inv[j]%mod;
        for(int j=0;j<=M;++j)A[j]=0;
        for(int j=1;j<=n;++j)A[j]=inv[j+2];
        fft(dp[i],M,0),fft(A,M,0);
        for(int j=0;j<M;++j)A[j]=(ll)A[j]*dp[i][j]%mod;
        fft(A,M,1);
        for(int j=1;j<=n;++j)
            dp[i+1][j]=(dp[i+1][j]+(ll)A[j]*fac[j+2])%mod;
    }
    int ans=0;
//  for(int i=0;i<=n;++i)printf("[%d]",dp[m][i]);
    for(int i=0;i<=n;++i)ans=(ans+(ll)C(i,n)*dp[m][i])%mod;
    printf("%d",ans);
}