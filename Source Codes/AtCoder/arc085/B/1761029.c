#include <stdio.h>

long long int abs(long long int a){return a>0?a:-a;}

int main(void){
    long long int N,Z,W;
    scanf("%lld %lld %lld",&N,&Z,&W);
    long long int a[N];
    for(int i=0;i<N;i++)scanf("%lld",&a[i]);
    if(N==1){printf("%lld",abs(a[0]-W));return 0;}
    long long int po[2][N];//0?X,1?Y???
    po[0][N-1]=abs(a[N-1]-a[N-2]);
    po[1][N-1]=abs(a[N-1]-a[N-2]);
    for(int i=N-2;i>0;i--){
        po[0][i]=abs(a[N-1]-a[i-1]);
        po[1][i]=abs(a[N-1]-a[i-1]);
        for(int j=i+1;j<N;j++){
            if(po[0][i]<po[1][j])po[0][i]=po[1][j];
            if(po[1][i]>po[0][j])po[1][i]=po[0][j];
        }
    }
    long long int ans=abs(a[N-1]-W);
    for(int i=1;i<N;i++)if(po[1][i]>ans)ans=po[1][i];
    printf("%lld",ans);
    return 0;
} ./Main.c:3:15: warning: conflicting types for built-in function ‘abs’
 long long int abs(long long int a){return a>0?a:-a;}
               ^
./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld",&N,&Z,&W);
     ^
./Main.c:9:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%lld",&a[i]);
                         ^