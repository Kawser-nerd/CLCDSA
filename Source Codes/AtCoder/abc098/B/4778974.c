#include <stdio.h>
int main(void){
    int n,x[30]={0},y[30]={0},i,j,t,ans=0;
    char s[100];
    scanf("%d%s",&n,s);
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            x[(s[j]-97)]++;
        }
        for(j=i;j<n;j++){
            y[(s[j]-97)]++;
        }
        t=0;
        for(j=0;j<30;j++){
            if(x[j]*y[j]>0) t++;
            x[j]=0;
            y[j]=0;
        }
        if(ans<t) ans=t;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s",&n,s);
     ^