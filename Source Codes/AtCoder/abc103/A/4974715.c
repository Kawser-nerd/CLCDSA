# include <stdio.h>
#include <stdlib.h>

int cmp( const void *p, const void *q ) {
    return *(int*)p - *(int*)q;
}

int main(){
    int A[3];

    scanf("%d%d%d", &A[0], &A[1], &A[2]);

    qsort(A, 3, sizeof(int), cmp);

    int cost = 0;
    for (int i = 1; i < 3; ++i){
        cost += A[i] - A[i-1];
    }

    printf("%d", cost);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &A[0], &A[1], &A[2]);
     ^