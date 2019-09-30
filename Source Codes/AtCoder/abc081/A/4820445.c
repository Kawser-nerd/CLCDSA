#include <stdio.h>

int main(void){
    char order[10];
    int j = 0;
    fgets(order, 10, stdin);
    if(order[0] == '1')
        j++;
    if(order[1] == '1')
        j++;
    if(order[2] == '1')
        j++;
    printf("%d\n", j);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(order, 10, stdin);
     ^