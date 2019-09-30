#include <stdio.h>

int main(void)
{
    int N, M;
    int a, b;
    int ab[100000];
    int ai, bi,
        aj, bj;
    int i;
    int ctr = 1;
     
    
    scanf("%d %d", &N, &M);
    
    
    for(i=1; i<N; i++)
        ab[i] = 999999;
    
    
    for(i=1; i<=M; i++)
    {
        scanf("%d %d", &a, &b);
        
        if(ab[a] > b)
            ab[a] = b;
    }
    
    for(i=1; i<N; i++) 
    {
        if(ab[i] != 999999)
        {
            ai = i;
            bi = ab[i];
            
            break;
        }
    }
    
    for(; i<N; i++)
    {
        if(ab[i] != 999999)
        {
            aj = i;
            bj = ab[i];
            
            if(bi <= aj)
            {
                ai = aj;
                bi = bj;
                ctr++;
            }
            else
            {
                ai = aj;
                        
                if(bi > bj)
                    bi = bj;
            }
        }
    }
    
    printf("%d\n", ctr);

    //system("pause");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a, &b);
         ^