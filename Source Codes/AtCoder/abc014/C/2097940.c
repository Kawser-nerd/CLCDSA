#include <stdio.h>
#include <stdlib.h>
int x[1000001]={0};

int main(){
    int n;
    scanf("%d",&n);

    int a,b;
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        x[a]++;
        x[b+1]--;
    }
    int ans=-1;
    for(i=0;i<=1000000;i++){
        if(i)x[i]+=x[i-1];
        if(x[i]>ans)ans=x[i];
    }
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^