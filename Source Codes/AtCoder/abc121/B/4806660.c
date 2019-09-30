#include <stdio.h>

int main(void)
{
    int n, m, c;
    int b[20];
    int a[20][20];

    int i, j;
    int count, sum;

    scanf("%d %d %d", &n, &m, &c);

    for(i=0;i<m;i++){
        scanf("%d", &b[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d", &a[j][i]);
        }
    }

    count = 0;
    for(i=0;i<n;i++){
        sum = 0;
        for(j=0;j<m;j++){
            sum += a[j][i] * b[j];
        }
        sum += c;
        if(sum > 0){
            count++;
        }
    }

    printf("%d", count);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &m, &c);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &b[i]);
         ^
./Main.c:19:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &a[j][i]);
             ^