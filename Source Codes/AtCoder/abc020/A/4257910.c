#include <stdio.h>
int main(void){
    int Q = 0;
    scanf("%ld", &Q);
    if(Q == 1) {
        printf("ABC\n");
    }else {
        printf("chokudai\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld", &Q);
           ^
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &Q);
     ^