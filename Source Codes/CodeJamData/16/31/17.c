#include<stdio.h>


char getsmallest (int* P, int N)
{
    int i, s=0;
    for(i=1; i<N; i++)
        if(P[s] < P[i])
            s = i;
    P[s]--;
    return (char)s;
}


int main()
{
    int x, T;
    int i, sum, N;
    char j, k;
    int P[1000];

    scanf("%d", &T);

    for(x=1; x<=T; x++)
    {
        scanf("%d", &N);
        for(sum=0, i=0; i<N; i++) { scanf("%d", P+i); sum += P[i]; }

        printf("Case #%d:", x);
        while(1)
        {
            j = getsmallest(P,N);
            if(sum==N && N&1) { sum--; printf(" %c", 'A'+j); continue; }
            if(--sum==0) { printf(" %c\n", 'A'+j); break; }
            k = getsmallest(P,N);
            printf(" %c%c", 'A'+j, 'A'+k);
            if(--sum==0) { printf("\n"); break; }
        }
    }
}

