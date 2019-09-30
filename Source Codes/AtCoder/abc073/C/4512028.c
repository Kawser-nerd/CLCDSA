#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100001

typedef struct{
    int data;
    int tag;
}Ae;
Ae a[MAX]={{0,0}};
int find(int n)
{
    int c=n%100000;
    while(1)
    {
        if(c>100000)
            c=0;
        if(a[c].data==n&&a[c].tag==0)
        {
            a[c].tag=1;
            return 0;
        }
        else if(a[c].data==n&&a[c].tag==1)
        {
            a[c].tag=0;
            return 1;
        }
        else if(a[c].data==0)
        {
            a[c].data=n;
            a[c].tag=1;
            return 0;
        }
        else c++;
    }
}

int main()
{
    int N,i,count=0,n;
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        scanf("%d",&n);

         if(find(n)==1)
         {
             count--;
         }else
         {
             count++;
         }

    }
    printf("%d\n",count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:45:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^