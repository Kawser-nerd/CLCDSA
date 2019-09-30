#include <stdio.h>
int main(void){
    // Your code here!
    int n,m1=1,m2=0,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(m1<x){
            m2 = m1;
            m1 = x;
        }
        if(m2<x && m1 != x)
            m2 = x;
    }
    printf("%d\n",m2);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^