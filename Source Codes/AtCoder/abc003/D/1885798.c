#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
#define PRINT(d) printf("%lld\n",d)

long long int p[901][901];
long long int pattern[31][31]={0};
long long int ans;
int R,C;
int X,Y;
int D,L;

void PascalT(int n){
    int i,j;
    long long int tmp1,tmp2;
    for(i=0;i<=n;i++){
        p[i][0]=1;
        for(j=1;j<i;j++){
            p[i][j]=(p[i-1][j-1]+p[i-1][j])% MOD;
            //printf("%lld ",p[i][j]);
        }
        //printf("\n");
        p[i][i]=1;
    }
    //printf("p[%d][%d]=%lld, p[%d][%d]=%lld\n",n,D+L,p[n][D+L],D+L,D,p[D+L][D]);
}

int main()
{
    scanf("%d %d",&R,&C);
    scanf("%d %d",&X,&Y);
    scanf("%d %d",&D,&L);
    PascalT(X*Y);
    ans=(p[X*Y][D]*p[X*Y-D][L])%MOD;//PRINT(ans);
    int flag=0;
    if(X>1&&(X-1)*Y>=D+L){
        ans-=((p[(X-1)*Y][D]*p[(X-1)*Y-D][L])%MOD*2)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//PRINT(p[(X-1)*Y][D]);PRINT(p[(X-1)*Y-D][L]);PRINT((p[(X-1)*Y][D]*p[(X-1)*Y-D][L])%MOD);PRINT((p[(X-1)*Y][D]*p[(X-1)*Y-D][L])%MOD*2);PRINT(((p[(X-1)*Y][D]*p[(X-1)*Y-D][L])%MOD*2)%MOD);
    //printf("x-1    :%lld %lld\n",(p[(X-1)*Y][D]*p[(X-1)*Y-D][L])%MOD,ans);
    if(Y>1&&X*(Y-1)>=D+L){
        ans-=((p[X*(Y-1)][D]*p[X*(Y-1)-D][L])%MOD*2)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//printf("    y-1:%lld %lld\n",(p[X*(Y-1)][D]*p[X*(Y-1)-D][L])%MOD,ans);
    if(X>1&&Y>1&&(X-1)*(Y-1)>=D+L){
        ans+=((p[(X-1)*(Y-1)][D]*p[(X-1)*(Y-1)-D][L])%MOD*4)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//printf("x-1 y-1:%lld %lld\n",(p[(X-1)*(Y-1)][D]*p[(X-1)*(Y-1)-D][L])%MOD,ans);
    if(X>2&&(X-2)*Y>=D+L){
        ans+=((p[(X-2)*Y][D]*p[(X-2)*Y-D][L])%MOD)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//printf("x-2    :%lld %lld\n",(p[(X-2)*Y][D]*p[(X-2)*Y-D][L])%MOD,ans);
    if(Y>2&&X*(Y-2)>=D+L){
        ans+=((p[X*(Y-2)][D]*p[X*(Y-2)-D][L])%MOD)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//printf("    y-2:%lld %lld\n",(p[X*(Y-2)][D]*p[X*(Y-2)-D][L])%MOD,ans);
    if(X>2&&Y>1&&(X-2)*(Y-1)>=D+L){
        ans-=((p[(X-2)*(Y-1)][D]*p[(X-2)*(Y-1)-D][L])%MOD*2)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//printf("x-2 y-1:%lld %lld\n",(p[(X-2)*(Y-1)][D]*p[(X-2)*(Y-1)-D][L])%MOD,ans);
    if(X>1&&Y>2&&(X-1)*(Y-2)>=D+L){
        ans-=((p[(X-1)*(Y-2)][D]*p[(X-1)*(Y-2)-D][L])%MOD*2)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//printf("x-1 y-2:%lld %lld\n",(p[(X-1)*(Y-2)][D]*p[(X-1)*(Y-2)-D][L])%MOD,ans);
    if(X>2&&Y>2&&(X-2)*(Y-2)>=D+L){
        ans+=((p[(X-2)*(Y-2)][D]*p[(X-2)*(Y-2)-D][L])%MOD)%MOD;
        if(ans>=0)ans%=MOD;
        else ans+=MOD;
    }//printf("x-2 y-2:%lld %lld\n",(p[(X-2)*(Y-2)][D]*p[(X-2)*(Y-2)-D][L])%MOD,ans);
    int space=(R-X+1)*(C-Y+1);
    ans=(ans*space)%MOD;
    printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&R,&C);
     ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&X,&Y);
     ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&D,&L);
     ^