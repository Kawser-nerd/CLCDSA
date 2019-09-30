#include <stdio.h>
#include <stdlib.h>

int compare_down(const void*a, const void*b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    int A_F[5], sum[10], i, j, k, count = 0, flag = 0, ans;

    scanf("%d %d %d %d %d", &A_F[0], &A_F[1], &A_F[2], &A_F[3], &A_F[4]);

    for(i=0; i<5; i++) {
        for(j=i+1; j>i && j<5; j++) {
            for(k=j+1; k>j && k<5; k++) {
                sum[count++] = A_F[i]+A_F[j]+A_F[k];
            }
        }
    }
    qsort(sum, 10, sizeof(int), compare_down);
    for(i=0; i<9; i++) {
        if(sum[i] != sum[i+1])
            flag++;
        if(flag == 2) {
            ans = sum[i+1];
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d %d", &A_F[0], &A_F[1], &A_F[2], &A_F[3], &A_F[4]);
     ^