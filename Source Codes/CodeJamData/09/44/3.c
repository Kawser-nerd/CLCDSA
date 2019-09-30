#include <stdio.h>
#include <math.h>
long     n;
double   x[4],y[4],r[4];
double   ans;
double   count(double X1,double Y1,double R1,double X2,double Y2,double R2){
         double dist = sqrt( (X2-X1)*(X2-X1) + (Y2-Y1)*(Y2-Y1) ); 
         if(R2>=R1 && R2-dist>=R1)      return R2;
         else if(R1>=R2 && R1-dist>=R2) return R1;
         else return (R1+R2+dist)/2;
}
double   max(double a,double b){
         if(a>b) return a;
         else    return b;   
}
int      main(){
         long i,t,z;
         freopen("D-small.in","r",stdin);
         freopen("D-small.out","w",stdout);
         scanf("%ld",&t);
         for(t,z=1;t;t--,z++){
             scanf("%ld",&n);
             for(i=1;i<=n;i++)
              scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
             if(n==1)          ans=r[1];
             else if(n==2)     ans=max(r[1],r[2]);
             else{
                               ans=99999999.0;
                               if(    max(count(x[1],y[1],r[1],x[2],y[2],r[2]),r[3])<ans )
                               ans =  max(count(x[1],y[1],r[1],x[2],y[2],r[2]),r[3]);
                               if(    max(count(x[2],y[2],r[2],x[3],y[3],r[3]),r[1])<ans )
                               ans =  max(count(x[2],y[2],r[2],x[3],y[3],r[3]),r[1]);
                               if(    max(count(x[1],y[1],r[1],x[3],y[3],r[3]),r[2])<ans )
                               ans =  max(count(x[1],y[1],r[1],x[3],y[3],r[3]),r[2]);
             }
             printf("Case #%ld: %.6lf\n",z,ans);
         }
         return 0;
}
