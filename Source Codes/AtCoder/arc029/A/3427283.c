#include <stdio.h>
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a<b?b:a;}
int main(void){
    int n,sum=0,ans=1e9;
    scanf("%d",&n);
    int t[n];
    for (int i=0; i<n; i++){
        scanf("%d",&t[i]);
        sum+=t[i];
    }
    for (int i=0; i<(1<<n); i++){
        int tmp=0;
        for (int j=0; j<n; j++){
            if ((1&i>>j)==1){
                tmp+=t[j];
            }
        }
        ans=min(ans,max(tmp,sum-tmp));
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t[i]);
         ^