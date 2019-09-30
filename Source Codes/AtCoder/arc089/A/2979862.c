#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    int t[100005],x[100005],y[100005];
    int can=1;
    scanf("%d",&n);
    t[0]=0,x[0]=0,y[0]=0;
    for(int i=1; i<=n; i++){
        scanf("%d%d%d",&t[i],&x[i],&y[i]);
    }

    for(int i=1; i<=n; i++){
        if((t[i]-t[i-1]) < (abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))){
            can=0;
            break;
        }
        if((t[i]-t[i-1])%2 != (abs(x[i]-x[i-1]+abs(y[i]-y[i-1])))%2 ){
            can=0;
            break;
        }
    }
    if(can)printf("Yes\n");
    else printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:29: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
         if((t[i]-t[i-1]) < (abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))){
                             ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&t[i],&x[i],&y[i]);
         ^