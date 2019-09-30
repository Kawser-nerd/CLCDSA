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

/* aがbの厳密に内部なら2 */
int isCircleInCircle(circle a,circle b){return doubleSign(b.r-a.r-pntDistance(a.c,b.c))+1;}

pnt pntPolar(double r,double t){pnt a; a.x=r*cos(t); a.y=r*sin(t); return a;}
void pntSort(pnt d[],int s){int i,j;pnt k,t;if(s<=1)return;k=pntMultipleDouble(pntPlus(d[0],d[s-1]),1/2.0);i=-1;j=s;for(;;){while(pntSign(pntMinus(d[++i],k))==-1);while(pntSign(pntMinus(d[--j],k))==1);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}pntSort(d,i);pntSort(d+j+1,s-j-1);}



/* a x^2 + b x + c = 0 を解く．戻り値は解の数．解の数が2ならres1 < res2． */
/* 解の数が無限なら return 3; */
int doubleSolveSecondDegreeEquation(double a,double b,double c,double *res1,double *res2){
  if(doubleSign(a)){
    double d=b*b-4*a*c; int m=doubleSign(d)+1;
    if(m==1) *res1=-b/(2*a);
    if(m==2){d=sqrt(d); *res1=(-b-d)/(2*a); *res2=(-b+d)/(2*a);}
    return m;
  }
  if(doubleSign(b)){*res1 = -b/c; return 1;}
  if(doubleSign(c)) return 0; return 3;
}

/* 直線 t と円 s の交点を求める．戻り値は交点の数．(3次元での球-直線の交点とほぼ同じコード) */
/* 2点で交わるなら，res1はt.aに近い側，res2はt.bに近い側 */
int pntIntersectionLineCircle(line t,circle s,pnt *res1,pnt *res2){
  int m; double a,b,c,t1,t2,k1,k2; pnt ab=pntMinus(t.b, t.a);
  a=b=0; c=-s.r*s.r;
  t1=t.a.x-s.c.x; t2=t.b.x-t.a.x; a+=t2*t2; b+=2*t1*t2; c+=t1*t1;
  t1=t.a.y-s.c.y; t2=t.b.y-t.a.y; a+=t2*t2; b+=2*t1*t2; c+=t1*t1;
  m=doubleSolveSecondDegreeEquation(a,b,c,&k1,&k2);
  if(m>=1) *res1 = pntPlus( t.a, pntMultipleDouble(ab,k1) );
  if(m>=2) *res2 = pntPlus( t.a, pntMultipleDouble(ab,k2) );
  return m;
}

/* 線分 t (端は含む) と円 s の交点を求める．戻り値は交点の数．(3次元での球-直線の交点とほぼ同じコード) */
/* 2点で交わるなら，res1はt.aに近い側，res2はt.bに近い側 */
int pntIntersectionSegmentCircle(line t,circle s,pnt *res1,pnt *res2){
  int m; double a,b,c,t1,t2,k1,k2; pnt ab=pntMinus(t.b, t.a);
  a=b=0; c=-s.r*s.r;
  t1=t.a.x-s.c.x; t2=t.b.x-t.a.x; a+=t2*t2; b+=2*t1*t2; c+=t1*t1;
  t1=t.a.y-s.c.y; t2=t.b.y-t.a.y; a+=t2*t2; b+=2*t1*t2; c+=t1*t1;
  m=doubleSolveSecondDegreeEquation(a,b,c,&k1,&k2);
  if(m>=2) if(doubleSign(k2)==-1 || doubleSign(k2-1)==1) m--;
  if(m>=1) if(doubleSign(k1)==-1 || doubleSign(k1-1)==1) k1=k2, m--;
  if(m>=1) *res1 = pntPlus( t.a, pntMultipleDouble(ab,k1) );
  if(m>=2) *res2 = pntPlus( t.a, pntMultipleDouble(ab,k2) );
  return m;
}

/* ax + by + c = 0 を表す直線を返す (制約: a=b=0ではない) */
line pntGetLineFromCoefficient(double a,double b,double c){
  line res;
  if( doubleSign(a)==0 ){
    res.a.x = 0; res.b.x = 1;
    res.a.y = res.b.y = -c/b;
  } else {
    res.a.y=0; res.b.y=1;
    res.a.x=-c/a; res.b.x=(-b-c)/a;
  }
  return res;
}

/* 2つの円の交点を求める．戻り値の値は交点の数．戻り値が3ならば無限点で交わる */
int pntIntersectionCircleCircle(circle s1,circle s2,pnt *res1,pnt *res2){
  double a,b,c; line t;
  double x1=s1.c.x, x2=s2.c.x, y1=s1.c.y, y2=s2.c.y, r1=s1.r, r2=s2.r;
  if( pntIsEqual(s1.c,s2.c) ){ if( doubleSign(s1.r-s2.r)==0 ) return 3; return 0; }
  a = 2*(x1-x2); b = 2*(y1-y2);
  c = (x2*x2-x1*x1) + (y2*y2-y1*y1) - (r2*r2-r1*r1);
  t = pntGetLineFromCoefficient(a,b,c);
  return pntIntersectionLineCircle(t,s1,res1,res2);
}


void doubleSort(double d[],int s){int i,j;double k1,k2,t;if(s<=1)return;k1=(d[0]+d[s-1])/2.0;k2=k1+EPS;k1-=EPS;i=-1;j=s;for(;;){while(d[++i]<k1);while(d[--j]>k2);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}doubleSort(d,i);doubleSort(d+j+1,s-j-1);}
void doubleIntSort(double d[],int m[],int s){int i,j,r;double k1,k2,t;if(s<=1)return;k1=(d[0]+d[s-1])/2.0;k2=k1+EPS;k1-=EPS;i=-1;j=s;for(;;){while(d[++i]<k1);while(d[--j]>k2);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;r=m[i];m[i]=m[j];m[j]=r;}doubleIntSort(d,m,i);doubleIntSort(d+j+1,m+j+1,s-j-1);}

double y[100000], yy; int ys;
double x[1000]; int xx[1000], xs;

/* integral[y=Y1..Y2] sqrt(R^2 - (y-Y)^2) dy を計算する */
double integ(double R,double Y,double Y1,double Y2){
  double th1,th2,res;

  Y1-=Y; Y2-=Y;
  Y1/=R; Y2/=R;
  if(Y1<-1) Y1=-1; if(Y1>1) Y1=1;
  if(Y2<-1) Y2=-1; if(Y2>1) Y2=1;
  th1 = acos(Y1); th2 = acos(Y2);

  res = (th2-th1) - (sin(2*th2)-sin(2*th1))/2;
  res *= -R*R/2;
  return res;
}

double cal(circle c[], int n){
  int i,j,k,l,m;
  int a,b,now;
  pnt p1,p2;
  double res, cen, add, X,Y,R,Y1,Y2;

  res=0;

  ys=0;
  rep(i,n){
    y[ys++] = c[i].c.y+c[i].r;
    y[ys++] = c[i].c.y-c[i].r;
  }
  rep(i,n) REP(j,i+1,n){
    k = pntIntersectionCircleCircle(c[i],c[j],&p1,&p2);
    if(k==0||k==3) continue;
    if(k>=1) y[ys++]=p1.y;
    if(k>=2) y[ys++]=p2.y;
  }
  
  doubleSort(y,ys);
  
  REP(k,1,ys){
    if( doubleSign(y[k]-y[k-1])!=1 ) continue;
    yy = (y[k]+y[k-1])/2;
    
    xs=0;
    rep(i,n){
      if(yy > c[i].c.y+c[i].r) continue;
      if(yy < c[i].c.y-c[i].r) continue;
      
      cen = c[i].c.x; add = yy-c[i].c.y; add = sqrt(c[i].r*c[i].r-add*add);
      x[xs]=cen-add; xx[xs++]=i;
      x[xs]=cen+add; xx[xs++]=i+n;
    }
    
    doubleIntSort(x,xx,xs);
    now=0;
    rep(m,xs){
      if(xx[m]<n){
        if(now==0) a=xx[m];
        now++;
      }
      if(xx[m]>=n){
        if(now==1) b=xx[m];
        now--;
      }
      if(now==0){
        Y1=y[k-1]; Y2=y[k];
        X=c[a].c.x;
        Y=c[a].c.y;
        R=c[a].r;
        res -= X*(Y2-Y1) - integ(R,Y,Y1,Y2);
        X=c[b-n].c.x;
        Y=c[b-n].c.y;
        R=c[b-n].r;
        res += X*(Y2-Y1) + integ(R,Y,Y1,Y2);
      }
    }
  }

  return res;
}


pnt pn[10000], pm[10000];
circle c[10000];
int main(){
  int i,j,k,l,m,n;
  double res;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&n,&m);
    rep(i,n) scanf("%lf%lf",&pn[i].x,&pn[i].y);
    rep(i,m) scanf("%lf%lf",&pm[i].x,&pm[i].y);

    printf("Case #%d:",++count);
    rep(i,n) c[i].c = pn[i];
    rep(k,m){
      rep(i,n) c[i].r = pntDistance(pn[i],pm[k]);
      res = -cal(c, n);
      rep(i,n) res += c[i].r * c[i].r * PI;
      printf(" %.8lf",res);
    }
    puts("");
  }

  return 0;
}

