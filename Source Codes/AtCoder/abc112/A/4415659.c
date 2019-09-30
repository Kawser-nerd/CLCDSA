#include <stdio.h>

int main(void){

    int age;

    scanf("%d",&age);

    if (age == 1){
        printf("Hello World");
    }
    else{ 
        int A,B;
        scanf("%d%d",&A,&B);
        printf("%d",A + B);
    }
    return 0;

} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&age);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&A,&B);
         ^