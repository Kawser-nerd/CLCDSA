#include <stdio.h>
int main()
{
    int n;
    int weight[51];
    int pile=0;
    int max[52]={0};
    scanf("%d",&n);
    int top_max=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);
    }
    for(int j=0;j<n;j++)
    {
        if(top_max<weight[j])
           {
          pile++;
          max[pile]=weight[j];
          top_max=weight[j];
           }
           else
           {
               for(int k=1;k<=pile;k++)
               {
                   if(max[k]>=weight[j])
                   {
                       max[k]=weight[j];
                       break;
                   }

               }
               for(int f=1;f<=pile;f++)
               { top_max=0;
                   if(top_max<max[f])
                   {
                       top_max=max[f];
                   }
               }
           }

    }
    printf("%d\n",pile);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&weight[i]);
         ^