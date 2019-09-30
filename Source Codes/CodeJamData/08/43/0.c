#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define N 1200
#define ST 0.95

double ab(double x){
  if(x>0) return x; return -x;
}

int main(){
  int i,j,k,l,m,n,rr;
  double x[2000],y[2000],z[2000],p[2000];
  double nx,ny,nz,eps,tmp,opt,d;

  int size,count=0;
  scanf("%d",&size);

  while(size--){
    scanf("%d",&n);
    rep(i,n) scanf("%lf%lf%lf%lf",x+i,y+i,z+i,p+i);

    nx=ny=nz=0;
    eps=1000000;
    rep(rr,N){
      opt=-1;
      rep(i,n){
        d = ab(x[i]-nx)+ab(y[i]-ny)+ab(z[i]-nz);
        d/=p[i];
        if(opt<d) opt=d, k=i;
      }
      if(x[k]<nx) nx-=eps; else nx+=eps;
      if(y[k]<ny) ny-=eps; else ny+=eps;
      if(z[k]<nz) nz-=eps; else nz+=eps;
      eps *= ST;
    }

    printf("Case #%d: %.8lf\n",++count,opt);
  }
  
  return 0;
}
