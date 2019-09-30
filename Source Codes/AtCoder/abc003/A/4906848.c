#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B;
    scanf("%d",&A);
    for(int i=1;i<=A;i++){
        B+=i;
    }
      B=B*10000;
    printf("%d\n",B/A);
    
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^