#include<stdio.h>

int main(){
    int x;

    scanf("%d",&x);

    if(x>=1200){
        printf("ARC");
    }else{printf("ABC");}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^