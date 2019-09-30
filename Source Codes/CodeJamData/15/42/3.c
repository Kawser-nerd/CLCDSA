#include<stdio.h>
#include<stdlib.h>
#define NEAR2(A,B) ((A)+1e-18>(B)&&(B)+1e-18>(A))
#define NEAR(A,B) ((A)==(B))

double dete(double a,double b,double c,double d){
  return a*d-b*c;
}

double doublemax(double a,double b){
  return a>b?a:b;
}
double r[101],c[101];
double v,x;
int n;

int main(int argc,char*argv[]){
  int ncase,nc;
  int a;
  scanf("%d",&ncase);
  for(nc=1;nc<=ncase;nc++){
    scanf("%d%lf%lf",&n,&v,&x);
    for(a=0;a<n;a++){
      scanf("%lf%lf",r+a,c+a);

    }
    printf("Case #%d: ",nc);
    double ans;
    if(n==1){
      if(c[0]!=x)goto impo;
      ans=v/r[0];
    }
    else{
      if((c[0]<x&&c[1]<x)||(c[0]>x&&c[1]>x))goto impo;
      double d,dx,dy;
      d=dete(r[0]*c[0],r[1]*c[1],r[0],r[1]);
      dx=dete(v*x,r[1]*c[1],v,r[1]);
      dy=dete(r[0]*c[0],v*x,r[0],v);
      if((NEAR(d,0)&&NEAR(dx,0)&&NEAR(dy,0))||
      (NEAR(c[0],x)&&NEAR(c[1],x))){
if(NEAR(c[0],x)==0||NEAR(c[1],x)==0){printf("%.18lf\n",d,r[0],c[0],r[1],c[1]);exit(-1);}
        ans=v/(r[0]+r[1]);
      }
      else{
if(NEAR(d,0)){printf("error2");exit(-1);}
//if(NEAR(dx/d*r[0]*c[0]+dy/d*r[1]*c[1],v*x)==0){puts("error3");exit(-1);}
        ans=doublemax(dx/d,dy/d);
      }
    }

    printf("%.8lf\n",ans);
    continue;
    impo:
    puts("IMPOSSIBLE");
  }
  return 0;
}
