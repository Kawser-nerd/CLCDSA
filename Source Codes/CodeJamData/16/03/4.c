#include <stdio.h>
#include <stdlib.h>

int N=32;
int J=500;

int main()
{
    int k,j,n;
    printf("Case #1:\n");
    for (j=0;j<J;j++) {
        printf("1");
        k=j;
        for (n=2;n<N;n+=2) {
            printf("%d%d", k&1, k&1);
            k>>=1;
        }
        printf("1 3 4 5 6 7 8 9 10 11\n");
    }
    return 0;
}
