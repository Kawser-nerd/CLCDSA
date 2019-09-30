#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NP_N 100000001
#define NP_N_2 10001
char np[NP_N] = {1, 1, 0};
//int p[12345678], pNum = 0;
int record[10];
void countPrime()
{
    int i, j, k;
    for(i=4;i<NP_N;i+=2)
    {
        np[i] = 1;
    }
    for(i=9;i<NP_N;i+=6)
    {
        np[i] = 1;
    }

    for(i=6;i<NP_N_2;i+=6)
    {
        if(!np[i-1])
        {
            for(j=(i-1)*(i-1), k=(i-1)*2;j<NP_N; j+=k)
            {
                np[j] = 1;
            }
        }
        if(!np[i+1])
        {
            for(j=(i+1)*(i+1), k=(i+1)*2;j<NP_N; j+=k)
            {
                np[j] = 1;
            }
        }
    }
    /*
    for(i=0;i<NP_N;++i)
    {
        if(!np[i])
        {
            p[pNum++] = i;
        }
    }
    */
}

int checkOk(int in, int d)
{
    long long int num=0;
    long long int i;
    for(i=1;in>0;i*=d)
    {
        //printf("#%5d %5lld %5d %5lld\n",in, i, (in&1), num);
        num += (in&1)*i;
        in >>= 1;
        //printf("%d %lld %lld\n",in, i, num);
    }

    for(i=0;i*i<=num && i<NP_N ;++i)
    {
        if(!np[i] && num%i==0)
        {
            record[d] = i;
            return 1;

        }
    }
    return 0;
}

void printBit(int in, int N)
{
    int i;
    for(i=N-1;i>=0;--i)
    {
        printf("%d",  (in>>i)&1 );
    }
}
void solve(int N, int J)
{
    int longN=N;
    if(N>16)
    {
        N/=2;

    }
    int limit = 1<<N;
    int checkBit = (1<<(N-1))+1;
    int i, j;
    int find = 0;
    for(i=0;i<limit;++i)
    //for(i=55;i<=55;++i)
    {
       if( (i&checkBit)!=checkBit  )
       {
           continue;
       }

       for(j=2;j<=10;++j)
       //for(j=3;j<=3;++j)
       {

           if(!checkOk(i, j))
           {
               break;
           }
       }
       if(j>10)
       {
           printBit(i, N);
           if(longN != N)
           {
               printBit(i, N);
           }
           for(j=2; j<=10; ++j)
           {
               printf(" %d", record[j]);
           }
           printf("\n");
           ++find;
           if(find >= J)
           {
               break;
           }
       }
    }
}

int main()
{
    countPrime();
    int t, T;
    int N, J;
    scanf("%d",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%d %d",&N, &J);
        printf("Case #%d:\n", t);
        solve(N, J);
    }

    return 0;
}
