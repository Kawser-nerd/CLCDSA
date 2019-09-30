#include <stdio.h>
int main(void){
    // Your code here!
    int n,w=0,s,t,cnt=0,x;
    scanf("%d%d%d",&n,&s,&t);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        w+=x;
        if(s<=w && w<=t)
            cnt++;
    }
    printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&s,&t);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^