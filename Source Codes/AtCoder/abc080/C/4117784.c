#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Ac//??
{
    long M[11];
};

int S(const void *a,const void *b)
    {
        return *(int*)b-*(int*)a;
    }

struct Time//??
{
    long as[10];
};



int main()
{
    long H[1024],k,R[100],t,n;
    long p[1024][10];
    struct Time mar[100];
    struct Ac ac[100];
    long i,j;
    long q;
    for(n=1;n<1024;n++)
    {
        k=n;
        for(i=0;i<10;i++)
        {
            t=pow(2,9-i);
            if(k/t!=1)
                p[n-1][i]=0;
            else
                p[n-1][i]=1;
            k%=t;
        }
    }
    
    scanf("%ld",&k);
    for(i=0;i<k;i++)
    {
        for(j=0;j<10;j++)
        {
            scanf("%ld",&mar[i].as[j]);
        }
    }//?????
    for(i=0;i<k;i++)
    {
        for(j=0;j<11;j++)
        {
            scanf("%ld",&ac[i].M[j]);
        }
    }//?????
    for(n=1;n<1024;n++)
    {
        for(i=0;i<k;i++)
        {
            R[i]=0;
        }
        for(i=0;i<10;i++)
        {
            for(j=0;j<k;j++)
            {
                if(mar[j].as[i]==1&&p[n-1][i]==1)
                    R[j]++;
            }
        }
        q=0;
        for(i=0;i<k;i++)
        {
            q=q+ac[i].M[R[i]];
        }
        H[n-1]=q;
    }
    qsort(H,1023,sizeof(H[0]),S);
    printf("%ld",H[0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:15: warning: implicit declaration of function ‘pow’ [-Wimplicit-function-declaration]
             t=pow(2,9-i);
               ^
./Main.c:34:15: warning: incompatible implicit declaration of built-in function ‘pow’
./Main.c:34:15: note: include ‘<math.h>’ or provide a declaration of ‘pow’
./Main.c:43:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&k);
     ^
./Main.c:48:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%ld",&mar[i].as[j]);
             ^
./Main.c:55:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%ld",&ac[i].M[j]);
             ^