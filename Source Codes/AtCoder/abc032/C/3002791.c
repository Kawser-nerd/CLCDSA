#include <stdio.h>

int main(void){
    int n,k;
    scanf("%d%d",&n,&k);
    int s[100005],ans=0;
    long long int temp=1;
    for(int i=0; i<n; i++){
        scanf("%d",&s[i]);
        if(s[i]==0)ans=n;
    }
    if(ans){
        printf("%d\n",ans);
        return 0;
    }
    int start=0,end=0;
    while(start<n){
        while(temp*s[end]<=k && end<n){
            temp*=s[end++];
        }
        if(start<end){
            if(temp<=k && ans <(end-start))ans=end-start;
            temp/=s[start++];
        }else break;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&s[i]);
         ^