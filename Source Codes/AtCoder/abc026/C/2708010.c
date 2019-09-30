#include <stdio.h>
#include <limits.h>

int main(void)
{
    int N, B[21], salary[21], i, j; 

    scanf("%d", &N);
    for(i=2; i<=N; i++) {
        scanf("%d", &B[i]);
    }
    salary[N] = 1;
    for(i=N; i>0; i--) {
        int max = 0, min = INT_MAX;
        int flag = 0;
        for(j=i+1; j<=N; j++) {
            if(B[j] == i) {
                flag = 1;
                if(max < salary[j])  max = salary[j];
                if(min > salary[j])  min = salary[j];
            }
        }
        if(!flag)  salary[i] = 1;
        else  salary[i] = max + min + 1;
    }
    printf("%d\n", salary[1]);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &B[i]);
         ^