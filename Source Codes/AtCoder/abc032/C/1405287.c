#include <stdio.h>

int main(void){
    int n,i,z=0;
    long long int k,seki=1;
    int s[100000];
    scanf("%d %lld",&n,&k);
    for(i=0;i<n;i++){scanf("%d",&s[i]);
        if(s[i]==0)z=1;
    }
    if(z==1){
        printf("%d\n",n);
        return 0;
    }
    int l=0,r=0,len,ans=0;
    while(l<n&&r<n){
        if(seki*s[r]<=k){
            seki*=s[r];
            r++;
        }
        else{
            if(l>=r)r++;
            else seki/=s[l];
            l++;
        }
        if(ans<r-l)
            ans=r-l;
        }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %lld",&n,&k);
     ^
./Main.c:9:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++){scanf("%d",&s[i]);
                      ^