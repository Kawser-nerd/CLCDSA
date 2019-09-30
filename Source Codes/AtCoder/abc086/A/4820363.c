#include <stdio.h>

int main(void){
    char order[10];
    int j, q, k;
    
    fgets(order, 10, stdin);
    sscanf(order, "%d %d", &j, &q);
    k = j * q % 2;
    if(k == 0)
        printf("Even\n");
    else
        printf("Odd\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(order, 10, stdin);
     ^