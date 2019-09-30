#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a, b, c, d;
    scanf("%d%d%d%d",&a, &b, &c, &d);
    printf("%s\n", (abs(c-a) <= d) || ((abs(b-a) <= d) && (abs(c-b) <= d)) ? "Yes" : "No");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a, &b, &c, &d);
     ^