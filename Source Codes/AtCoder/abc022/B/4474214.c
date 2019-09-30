#include <stdio.h>
int main(void){
    // Your code here!
    int n,x,c[100005]={0},cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(c[x]==0) c[x]=1;
        else cnt++;
    }
    printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^