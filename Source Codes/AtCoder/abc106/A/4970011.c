# include <stdio.h>

int main(){
    int A, B;

    scanf("%d%d", &A, &B);
    printf("%d", (A-1)*(B-1));

    return 0;
} ./Main.c: In function �main�:
./Main.c:6:5: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &A, &B);
     ^