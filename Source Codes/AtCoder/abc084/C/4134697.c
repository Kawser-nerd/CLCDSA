#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stations
{
    long c;
    long s;
    long f;
} station;
int main()
{
    station stat[501];
    long time[501],t;
    long n,i,j,k;
    while(scanf("%ld",&n)!=EOF)
    {
        for(i=0; i<n-1; i++)
        {
            scanf("%ld%ld%ld",&stat[i].c,&stat[i].s,&stat[i].f);
            time[i]=0;
        }
        time[n-1]=0;
        for(i=0; i<n-1; i++)
        {
            time[i]+=stat[i].s;
            for(j=0; j<=i; j++)
            {
                if(i!=j)
                {
                    t=time[j]-stat[i].s;
                    if(t<0)
                    {
                        time[j]=stat[i].s;
                    }else if(t%stat[i].f!=0)
                    {
                        t=((long)t/stat[i].f+1)*stat[i].f;
                        time[j]=stat[i].s+t;
                    }
                }
                //t=time[j]-stat[i].c-stat[i].f;
                time[j]+=stat[i].c;
            }
        }
        for(i=0; i<n; i++)
        {
            printf("%ld\n",time[i]);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%ld%ld%ld",&stat[i].c,&stat[i].s,&stat[i].f);
             ^