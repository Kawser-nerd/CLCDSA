#include <stdio.h>

int main(void){
    
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    
    for(int i=0; i<k && a<b; i++){
        printf("%d\n",a);
        a++;
    }
    for(int i=b-k+1; i<=b; i++){
        if(i>=a)
            printf("%d\n",i);
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&b,&k);
     ^