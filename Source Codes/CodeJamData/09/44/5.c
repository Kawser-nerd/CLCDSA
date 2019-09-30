#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


#define EPS 1e-10
#define PI 3.141592653589793238462
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
typedef struct struct_point{double x,y;}pnt;
typedef struct struct_line{pnt a,b;}line;
typedef struct struct_circle{pnt c; double r;}circle;

int doubleSign(double a){if(a>EPS) return 1; if(a<-EPS) return -1; return 0;}
int pntSign(pnt a){int i=doubleSign(a.x); if(i) return i; return doubleSign(a.y);}

pnt pntPlus(pnt a,pnt b){a.x+=b.x; a.y+=b.y; return a;}
pnt pntMinus(pnt a,pnt b){a.x-=b.x; a.y-=b.y; return a;}
pnt pntMultiple(pnt a,pnt b){pnt c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
pnt pntMultipleDouble(pnt a,double k){a.x*=k; a.y*=k; return a;}

int pntIsEqual(pnt a,pnt b){return pntSign(pntMinus(a,b))==0;}

double pntLength(pnt a){return sqrt(a.x*a.x+a.y*a.y);}
double pntLength2(pnt a){return a.x*a.x+a.y*a.y;}
double pntDistance(pnt a,pnt b){return pntLength(pntMinus(a,b));}
double pntDistance2(pnt a,pnt b){return pntLength2(pntMinus(a,b));}
double pntArgument(pnt a){return atan2(a.y,a.x);}

pnt pntNormalize(pnt a){double n=pntLength(a); a.x/=n; a.y/=n; return a;}
double pntInnerProduct(pnt a,pnt b){return a.x*b.x+a.y*b.y;}
double pntOuterProduct(pnt a,pnt b){return a.x*b.y-a.y*b.x;}

pnt pntGenerator(double x,double y){pnt res; res.x=x; res.y=y; return res;}
line pntToLine(pnt a,pnt b){line res; res.a=a; res.b=b; return res;}
circle pntToCircle(pnt c,double r){circle res; res.c=c; res.r=r; return res;}

int isPntInCircle(pnt p,circle c){return doubleSign(c.r-pntDistance(p,c.c))+1;}
int isPntOnCircle(pnt p,circle c){if(doubleSign(pntDistance(p,c.c)-c.r)==0) return 1; return 0;}

/* a‚ªb‚ÌŒµ–§‚É“à•”‚È‚ç2 */
int isCircleInCircle(circle a,circle b){return doubleSign(b.r-a.r-pntDistance(a.c,b.c))+1;}

pnt pntPolar(double r,double t){pnt a; a.x=r*cos(t); a.y=r*sin(t); return a;}
void pntSort(pnt d[],int s){int i,j;pnt k,t;if(s<=1)return;k=pntMultipleDouble(pntPlus(d[0],d[s-1]),1/2.0);i=-1;j=s;for(;;){while(pntSign(pntMinus(d[++i],k))==-1);while(pntSign(pntMinus(d[--j],k))==1);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}pntSort(d,i);pntSort(d+j+1,s-j-1);}





typedef struct struct_matrix{
  int r,c;
  double d[10][10];
}doubleMtx;

double doubleAbs(double a){
  if(a<0) return -a; return a;
}

int doubleSolveLinearEquation(doubleMtx a,double z[],double b[]){
  int i,j,k,r=a.r,c=a.c,m;
  int x=0,y,fg=0;
  double mx,mul;

  rep(y,c){
    if(x==r) break;
    if( !doubleSign(a.d[x][y]) ){
      mx=0;
      REP(i,x+1,r) if(mx < doubleAbs(a.d[i][y])) mx = doubleAbs(a.d[i][y]), k=i;
      if( !doubleSign(mx) ) {fg=1; continue;}
      rep(j,c) mx=a.d[x][j], a.d[x][j]=a.d[k][j], a.d[k][j]=mx;
      mx=b[x]; b[x]=b[k]; b[k]=mx;
    }
    rep(i,r){
      if(i==x) continue;
      mul = a.d[i][y]/a.d[x][y];
      rep(j,c) a.d[i][j]-=mul*a.d[x][j]; b[i]-=mul*b[x];
    }
    x++;
  }

  if(y!=c) return 2; /* multiple solution */
  for(i=r-1;i>=0;i--){
    rep(j,c) if( doubleSign(a.d[i][j]) ) break;
    if(j==c){
      if( doubleSign(b[i]) ) return 0; /* no solution */
    } else{
      z[j] = b[i]/a.d[i][j];
      if( z[j]-floor(z[j]+EPS) > EPS ) return 0;
    }
  }
  if(fg) return 2;
  return 1;
}


#define ll long long

void doubleIntSort(double d[],int m[],int s){int i,j,r;double k1,k2,t;if(s<=1)return;k1=(d[0]+d[s-1])/2.0;k2=k1+EPS;k1-=EPS;i=-1;j=s;for(;;){while(d[++i]<k1);while(d[--j]>k2);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;r=m[i];m[i]=m[j];m[j]=r;}doubleIntSort(d,m,i);doubleIntSort(d+j+1,m+j+1,s-j-1);}

int sz;
circle in[100],go[100000];
int ind[100000]; double dat[100000]; ll fg[100000], all;

int main(){
  int i,j,k,l,m,n;
  int size,count=0;
  double x[3],y[3];
  pnt a,b,c;
  doubleMtx mt;
  
  scanf("%d",&size);
  while(size--){
    scanf("%d",&n);
    rep(i,n) scanf("%lf%lf%lf",&in[i].c.x,&in[i].c.y,&in[i].r);

    sz=0;
    rep(i,n) go[sz++] = in[i];
    rep(i,n) REP(j,i+1,n){
      c=pntMinus(in[j].c,in[i].c);
      c=pntNormalize(c);
      a=pntPlus(in[i].c,pntMultipleDouble(c,-in[i].r));
      b=pntPlus(in[j].c,pntMultipleDouble(c, in[j].r));
      c=pntMultipleDouble(pntPlus(a,b),0.5);
      go[sz].c=c;
      go[sz].r=(in[i].r+in[j].r+pntDistance(in[i].c,in[j].c))/2;
      sz++;
    }
    rep(i,n) REP(j,i+1,n) REP(k,j+1,n){
      mt.r=mt.c=3;
      mt.d[0][0]= -2*(in[i].c.x-in[j].c.x);  mt.d[0][1]= -2*(in[i].c.y-in[j].c.y);  mt.d[0][2]=  2*(in[i].r  -in[j].r  );
      mt.d[1][0]= -2*(in[j].c.x-in[k].c.x);  mt.d[1][1]= -2*(in[j].c.y-in[k].c.y);  mt.d[1][2]=  2*(in[j].r  -in[k].r  );
      mt.d[2][0]= -2*(in[k].c.x-in[i].c.x);  mt.d[2][1]= -2*(in[k].c.y-in[i].c.y);  mt.d[2][2]=  2*(in[k].r  -in[i].r  );
      y[0] = (pow(in[i].r,2)-pow(in[j].r,2)) - (pow(in[i].c.x,2),pow(in[j].c.x,2)) - (pow(in[i].c.y,2),pow(in[j].c.y,2));
      y[1] = (pow(in[j].r,2)-pow(in[k].r,2)) - (pow(in[j].c.x,2),pow(in[k].c.x,2)) - (pow(in[j].c.y,2),pow(in[k].c.y,2));
      y[2] = (pow(in[k].r,2)-pow(in[i].r,2)) - (pow(in[k].c.x,2),pow(in[i].c.x,2)) - (pow(in[k].c.y,2),pow(in[i].c.y,2));
      m=doubleSolveLinearEquation(mt,x,y);
      if(m!=1) continue;
      go[sz].c.x=x[0];
      go[sz].c.y=x[1];
      go[sz].r  =x[2];
    }

    rep(i,sz) ind[i]=i, dat[i]=go[i].r;
    doubleIntSort(dat,ind,sz);

    rep(i,sz){
      fg[i]=0; k=ind[i];
      rep(j,n) if( isCircleInCircle(in[j],go[k]) ) fg[i]|=(1LL<<j);
    }

    all = (1LL<<n)-1;
    rep(i,sz){
      rep(j,i+1) if( (fg[i]|fg[j])==all ) break;
      if(j!=i+1) break;
    }

    printf("Case #%d: %.08lf\n",++count,go[ind[i]].r);
  }

  return 0;
}
