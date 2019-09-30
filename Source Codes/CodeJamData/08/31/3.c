#include<stdio.h>
#include<stdlib.h>
#define MX 2000
int N, P, K, L;
int freq[MX];
int main()
{
    int cs, i, j, mx, temp;
    unsigned long long int totsum;
    scanf("%d",&N);
    for(cs=1; cs<=N; cs++)
    {
              scanf("%d%d%d",&P,&K,&L);
              for(i=0;i<L;i++)
              scanf("%d",&freq[i]);
              
              for(i=0;i<L;i++)
              {
               mx = i;
               for(j=(i+1);j<L;j++)
               {
                if(freq[mx]<freq[j])
                mx = j;
               }
               temp = freq[mx];
               freq[mx] = freq[i];
               freq[i] = temp;
              }
              totsum = 0;
              for(i=0;i<L;i++)
              {
               totsum += (unsigned long long int)freq[i]*((unsigned long long int)(i/K)+1);
              }
              printf("Case #%d: %llu\n",cs, totsum);
    }
    system("PAUSE");
    return 0;
}
