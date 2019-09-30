#include <stdio.h>

int main(){
    
    int a;
    scanf("%d",&a);
    if(a%2 == 0){
        printf("%d\n",a);
    }else{
        printf("%d\n",a*2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^