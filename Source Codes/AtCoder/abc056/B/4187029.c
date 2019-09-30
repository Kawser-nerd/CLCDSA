#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
        int L[3];
        for (int i = 0; i < 3; i++) {
                scanf("%d", &L[i]);
        }
        if (L[1]>L[2]) {
                int tmp;
                tmp=L[1];
                L[1]=L[2];
                L[2]=tmp;
        }
        if ( L[2] <= L[0]+L[1]) {
                printf("0\n");
                return 0;
        }else{
                printf("%d\n",L[2]-L[1]-L[0]);
                return 0;
        }
} ./Main.c: In function ‘main’:
./Main.c:8:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d", &L[i]);
                 ^