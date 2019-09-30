#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int main(void){
    int n,ans=0,tmp=1;
    scanf("%d",&n);
    int p[n],q[n];
    for (int i=0; i<n; i++){
        scanf("%d",&p[i]);
        q[p[i]-1]=i+1;
    }
    for (int i=0; i<n-1; i++){
        if (q[i]<q[i+1]){
            tmp++;
        } else {
            ans=max(ans,tmp);
            tmp=1;
        }
    }
    printf("%d\n",n-max(ans,tmp));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&p[i]);
         ^