#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large1.out","w",stdout);
    int i,j,T,d,n,k,s;
    double temp,time;
    
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
       time=0;
       scanf("%d%d",&d,&n);
       for(j=0;j<n;j++)
       {
          scanf("%d %d",&k,&s);
          temp=(d-k)*1.0/s; 
          if(temp>time)
            time=temp;            
       }
       printf("Case #%d: %lf\n",i,d*1.0/time);


    }


    //system("pause");
    return 0;
}
