#include <stdio.h>

int main(){

    int A ,B;
    char op;

    //????????
    scanf("%d %c %d" ,&A ,&op ,&B);

    switch (op){
        case '+':
            printf("%d\n" ,A+B);
            break;
    
        case '-':
            printf("%d\n" ,A-B);
            break;
    }
    
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %c %d" ,&A ,&op ,&B);
     ^