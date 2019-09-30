#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C;
    scanf("%d",&A);

if(A%2==0){
    printf("%d",A);
}else{
    printf("%d",A*2);
}
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^