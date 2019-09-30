#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-9

int L, U;
double Lx[120], Ly[120];
double Ux[120], Uy[120];

double cal_under(double x[], double y[], int xs, double max_x){
  int i,j,k;
  double res = 0;

  double go;
  double y1, y2, dy;

  REP(i,1,xs){
    if(x[i-1] > max_x-EPS) break;

    if(x[i] < max_x+EPS) go = 1;
    else                 go = (max_x - x[i-1]) / (x[i] - x[i-1]);

    dy = y[i] - y[i-1];
    y1 = y[i-1];
    y2 = y[i-1] + dy * go;

    res += (y1 + y2) / 2 * go * (x[i] - x[i-1]);
  }

  return res;
}

double cal_between(double max_x){
  return cal_under(Ux,Uy,U,max_x) - cal_under(Lx,Ly,L,max_x);
}

int main(){
  int i,j,k,l,m,n;

  int per;
  double area, W, tmp, tar;

  double a,b,c;

  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%lf%d%d%d",&W,&L,&U,&per);
    rep(i,L) scanf("%lf%lf",Lx+i,Ly+i);
    rep(i,U) scanf("%lf%lf",Ux+i,Uy+i);

    printf("Case #%d:\n",++count);

    area = cal_between(W);
    REP(m,1,per){
      a=0; b=W;

      tar = area / per * m;
      
      while(b-a > EPS){
        c = (a+b)/2;
        tmp = cal_between(c);
        if(tmp < tar) a=c;
        else          b=c;
      }
      printf("%.8lf\n",(a+b)/2);
    }
  }

  return 0;
}
