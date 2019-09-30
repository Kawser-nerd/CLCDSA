#include<stdio.h>

double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}

typedef struct{
  double a;
  double b;
  long long par;
  long long left;
  long long right;
}func;

func fseg[4510000];
long long fc=1;

void finit(){
  fseg[0].a=1.0;
  fseg[0].b=0.0;
  fseg[0].par=-1;
  fseg[0].left=-1;
  fseg[0].right=-1;
  fseg[1].a=1.0;
  fseg[1].b=0.0;
  fseg[1].par=-1;
  fseg[1].left=0;
  fseg[1].right=0;
}

long long makeseg(long long t){
  long long i,w,p;
  p=1;
  for(i=39;i>=0;i--){
    if((t&(1ll<<i))==0){
      if(fseg[p].left==0){
        fc++;
        fseg[p].left=fc;
        fseg[fc].par=p;
        fseg[fc].a=1.0;
        fseg[fc].b=0.0;
        fseg[fc].left=0;
        fseg[fc].right=0;
      }
      p=fseg[p].left;
    }
    else{
      if(fseg[p].right==0){
        fc++;
        fseg[p].right=fc;
        fseg[fc].par=p;
        fseg[fc].a=1.0;
        fseg[fc].b=0.0;
        fseg[fc].left=0;
        fseg[fc].right=0;
      }
      p=fseg[p].right;
    }
  }
  return p;
}

void upd(long long t,double av,double bv){
  long long p;
  double la,lb,ra,rb;
  p=makeseg(t);
  fseg[p].a=av;
  fseg[p].b=bv;
  p=fseg[p].par;
  while(p!=-1){
    la=fseg[fseg[p].left].a;
    lb=fseg[fseg[p].left].b;
    ra=fseg[fseg[p].right].a;
    rb=fseg[fseg[p].right].b;
    fseg[p].a=la*ra;
    fseg[p].b=lb*ra+rb;
    p=fseg[p].par;
  }
}

int main(){
  finit();
  long long i,n,m,p;
  double av,bv;
  double rma=1.0,rmi=1.0;
  scanf("%lld%lld",&n,&m);
  for(i=0;i<m;i++){
    scanf("%lld%lf%lf",&p,&av,&bv);
    upd(p,av,bv);
    rma=dbmax(rma,fseg[1].a+fseg[1].b);
    rmi=dbmin(rmi,fseg[1].a+fseg[1].b);
  }
  printf("%.12lf\n%.12lf\n",rmi,rma);
} ./Main.c: In function ‘main’:
./Main.c:85:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&n,&m);
   ^
./Main.c:87:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lf%lf",&p,&av,&bv);
     ^