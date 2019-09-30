#include <stdio.h>

int main(void) {
    int A,B;
    if (scanf("%d %d",&A,&B) != EOF) {
        if (B % A == 0) {
            printf("%d", A+B);
        } else {
            printf("%d", B-A);
        }
    } else {
        return 1;
    }
    return 0;
}