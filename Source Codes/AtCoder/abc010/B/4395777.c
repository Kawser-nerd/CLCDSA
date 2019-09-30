#include <stdio.h>
int main(void){
    // Your code here!
    int n,m,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        while(m%3==2 || m%2==0){
            m--;
            s++;
        }
    }
    printf("%d\n",s);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&m);
         ^