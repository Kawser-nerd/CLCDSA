#include <stdio.h>
int main(void){
    // Your code here!
    int n;
    scanf("%d",&n);
    if(n==100) printf("Perfect\n");
    else if(n>=90) printf("Great\n");
    else if(n>=60) printf("Good\n");
    else printf("Bad\n");
    
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^