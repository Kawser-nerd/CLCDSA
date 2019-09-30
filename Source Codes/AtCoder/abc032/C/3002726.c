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
    if(ans==n){
        printf("%d\n",n);
        return 0;
    }
    int j=0;
    for(int i=0; i<n;){
        while(j<n){
            if(temp>k)break;
            temp*=s[j++];
            if(temp<=k && ans <(j-i))ans=j-i;
        }
        while(i<=j && temp > k){
            temp/=s[i++];
            if(temp<=k && ans <(j-i))ans=j-i;
        }
        if(j==0 || j==n)break;
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