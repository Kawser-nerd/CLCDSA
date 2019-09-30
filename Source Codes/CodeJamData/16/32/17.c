#include <stdio.h>

int main()
{
    int x, T;
    int i, j, B;
    char matrix[50][50];
    long long n, M;

    scanf("%d", &T);

    for(x=1; x<=T; x++)
    {
        scanf("%d %lld", &B, &M);
        printf("Case #%d:", x);
        n = 1<<(B-2);
        if(M > n) { printf(" IMPOSSIBLE\n"); continue; }
        printf(" POSSIBLE\n");

        for(i=0; i<B; i++)
        for(j=0; j<B; j++) matrix[i][j]=0;

        for(i=1; i<B-1; i++)
        for(j=i+1; j<B; j++) matrix[i][j]=1;

        if(n==M) { M--; matrix[0][B-1]=1; }

        for(j=B-2; j>0; j--)
        {
            matrix[0][j] = M&1;
            M = M>>1;
        }

        for(i=0; i<B; i++)
        {
            for(j=0; j<B; j++)
                printf("%d", matrix[i][j]);
            printf("\n");
        }
    }
}

