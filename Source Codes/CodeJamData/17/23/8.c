#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void walk(int sta,int des,int cfar,int cspeed,double ctime);
double time;
int dis[109],howfar[109],speed[109],flag;
int main()
{   
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int i,T,n,q,j,k,temp,sta,des;
   

    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
       flag=0;
       scanf("%d%d",&n,&q);
       time=0;
       
       for(j=1;j<=n;j++)
          scanf("%d %d",&howfar[j],&speed[j]);
       
       for(j=1;j<n;j++)
       {
          for(k=1;k<=j;k++)
             scanf("%d",&temp);
          scanf("%d",&dis[j]); 
          for(k=j+2;k<=n;k++)
             scanf("%d",&temp);                
       }
       for(k=1;k<=n;k++)
          scanf("%d",&temp);
       scanf("%d %d",&sta,&des);
       time=dis[1]*1.0/speed[1];
       walk(2,n,howfar[1]-dis[1],speed[1],time);
       
       
       printf("Case #%d: %lf\n",i,time);

    }


    //system("pause");
    return 0;
}
void walk(int sta,int des,int cfar,int cspeed,double ctime)
{
     if(sta==des)
     {
        if(flag==0||ctime<time)
        {   
            time=ctime; 
            flag=1;
        }        
        return;
     }
     if(cfar>=dis[sta])
       walk(sta+1,des,cfar-dis[sta],cspeed,ctime+dis[sta]*1.0/cspeed);
     if(howfar[sta]>=dis[sta])
       walk(sta+1,des,howfar[sta]-dis[sta],speed[sta],ctime+dis[sta]*1.0/speed[sta]); 
     return;   
}
