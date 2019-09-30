#include<stdio.h>
int main(void)
{
    int N,x;

    scanf("%d %d",&N,&x);
    if (N <= 2) {
        if (x == N) {
            printf("Yes\n");
            for (int i = 0; i < 2*N-1; i++) {
                printf("%d\n",i+1);
            }
        } else {
            printf("No\n");
        }
    } else  {
        if (x >= 2 && x <= 2*N-2) {
            printf("Yes\n");
            if (x == 2) {
                for (int i = 0; i < N-3; i++) {
                    printf("%d\n",i+4);
                }
                printf("3\n");
                printf("2\n");
                printf("1\n");
                printf("%d\n",2*N-1);
                for (int i = N+1; i < 2*N-1; i++){
                    printf("%d\n",i);
                }
            } else {
                int count = 3;
                for (int i = 0; i < N-3; i++) {
                    if (count==x) count++;
                    printf("%d\n",count);
                    count++;
                }
            printf("2\n");
                printf("%d\n",x);
                printf("%d\n",2*N-1);
                printf("1\n");
                for (int i = N+1; i < 2*N-1; i++) {
                    if (count==x) count++;
                    printf("%d\n",count);
                    count++;
                }
            }
        } else {
            printf("No\n");
        }
    }    
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&x);
     ^