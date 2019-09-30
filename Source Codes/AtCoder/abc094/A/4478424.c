#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    if(A+B<C){
        printf("NO");
    }else if(A>C){
        printf("NO");
    }else{
        printf("YES");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&C);
     ^