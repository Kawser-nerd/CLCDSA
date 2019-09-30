#include <stdio.h>

int main(){
    int n; scanf("%d",&n);
    int q=n/100;
    if(n<=100*q+10*q+q){
        printf("%d",100*q+10*q+q);
    }else{
        printf("%d",100*(q+1)+10*(q+1)+(q+1));
    }   
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n; scanf("%d",&n);
            ^