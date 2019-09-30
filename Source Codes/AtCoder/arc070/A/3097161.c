#include <stdio.h>

int main(void) {
    int x,i,zah = 0;
    scanf("%d",&x);
    for (i = 1;;i++) {
        zah += i;
        if (zah >= x) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^