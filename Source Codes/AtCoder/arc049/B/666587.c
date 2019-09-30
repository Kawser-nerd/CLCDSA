#include <stdio.h>
#include <math.h>

#define NMAX 1002

int main(){
     int N;
     int x[NMAX],y[NMAX],c[NMAX];

     int ret;
     int i,j;
     double X,Y;
     double max=0;
     double tmpc;

     ret=scanf("%d",&N);
     for(i=1;i<=N;i++){
          ret = scanf("%d %d %d",&x[i],&y[i],&c[i]);
     }

     max=0;
     for(i=1;i<=N-1;i++){
          for(j=i+1;j<=N;j++){
               tmpc=c[i]*c[j]/(double)(c[i]+c[j]);
               X=fabs(x[i]-x[j])*tmpc;
               Y=fabs(y[i]-y[j])*tmpc;

               if(max<X)max=X;
               if(max<Y)max=Y;
          }
     }

     printf("%lf\n",max);

}