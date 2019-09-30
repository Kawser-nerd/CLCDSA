#include<stdio.h>

int main(){
    int num;

    scanf("%d",&num);
    if(num==1){
        printf("ABC\n");
    }else{printf("chokudai\n");}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&num);
     ^