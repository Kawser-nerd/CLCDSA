#include <stdio.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
int a[100000];
int main(void){
    int n,i;
    int ans=0;
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n){
        ans++;
        while(a[i]==a[i+1]&&i+1<n) i++;
        if(a[i+1]-a[i]>0){
            while(a[i+1]-a[i]>=0&&i+1<n) i++;
        }
        else{
            while(a[i+1]-a[i]<=0&&i+1<n) i++;
        }
    }
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:16: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     FOR(i,0,n) scanf("%d",&a[i]);
                ^