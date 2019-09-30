#include <stdio.h>
int main(void){
    // Your code here!
    char c[5];
    int i;
    scanf("%s",c);
    for(i=1;i<4;i++){
        if(c[0]!=c[i])
            break;
    }
    if(i==4)
        printf("SAME\n");
    else
        printf("DIFFERENT\n");
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",c);
     ^