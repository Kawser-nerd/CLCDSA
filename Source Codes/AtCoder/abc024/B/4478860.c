#include <stdio.h>
int main(void){
    // Your code here!
    int n,t,num[1000001];
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    int cnt = t;
    for(int i=1;i<n;i++){
        if(num[i-1]+t<num[i])
            cnt += t;
        else
            cnt += num[i]-num[i-1];
    }
    printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&t);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&num[i]);
         ^