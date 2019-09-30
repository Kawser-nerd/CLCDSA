#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
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
int doubleSignR(double a,double b){ if(doubleSign(b)!=0 && doubleSign(a/b-1)==0) return 0; return doubleSign(a-b);}
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

/* 点oのまわりに点aをtだけ回転した点を返す */
pnt pntRatation(pnt a,pnt o,double t){
  return pntPlus(pntMultiple(pntMinus(a,o),pntPolar(1.0,t)),o);
}

pnt pntRatationEasy(pnt a,double t){
  return pntMultiple(a,pntPolar(1.0,t));
}

/* 直線の上に載っていると1, 載ってなければ0 */
int isPntOnLine(pnt a,line s){
  pnt ab; double r;
  ab=pntMinus(s.b,s.a); r=pntDistance(s.a,a)/pntDistance(s.a,s.b);
  if( !pntIsEqual(a,pntPlus(s.a,pntMultipleDouble(ab,r)) ) && !pntIsEqual(a,pntMinus(s.a,pntMultipleDouble(ab,r)) ) ) return 0;
  return 1;
}

/* 線分の上に載っていると2, 端点なら1, 載ってなければ0 */
int isPntOnSegment(pnt a,line s){
  pnt ab; double r;
  ab=pntMinus(s.b,s.a); r=pntDistance(s.a,a)/pntDistance(s.a,s.b);
  if( !pntIsEqual(a,pntPlus(s.a,pntMultipleDouble(ab,r)) ) ) return 0;
  if( doubleSign(r)==-1 || doubleSign(r-1)==1 ) return 0;
  if( doubleSign(r)==0  || doubleSign(r-1)==0 ) return 1;
  return 2;
}


/* 角度bacを返す */
double angleOfTriangle(pnt a,pnt b,pnt c){
  double inner,n1,n2;
  inner=pntInnerProduct(pntMinus(b,a),pntMinus(c,a));
  n1=pntDistance(a,b); n2=pntDistance(a,c);
  inner=inner/n1/n2;
  if(inner>1) inner=1; if(inner<-1) inner=-1;
  return acos(inner);
}

/* 線分上=1 中=2 外=0 */
int isInPolygon(pnt p,pnt poly[],int size){
  int i; double th=0;
  poly[size]=poly[0];

  rep(i,size) if( isPntOnSegment(p,pntToLine(poly[i],poly[i+1])) ) return 1;
  rep(i,size) th += pntSignAreaOfTriangle(p,poly[i],poly[i+1]) * angleOfTriangle(p,poly[i],poly[i+1]);
  if( -PI/2<th && th<PI/2 ) return 0; return 2;
}







/* 原点中心半径rの円に，pから接線を引いて，接線と円の交点を2つ求める */
/* 制約: pは円の外 */
void pntPointToCircleTangentialEasy(pnt p,double r,pnt *res1,pnt *res2){
  double a,b,c,d;
  if( doubleSign(p.x)==0 ){
    a=p.x; p.x=p.y; p.y=a;
    pntPointToCircleTangentialEasy(p,r,res1,res2);
    a=res1->x; res1->x=res1->y; res1->y=a;
    a=res2->x; res2->x=res2->y; res2->y=a;
    return;
  }
  a = pntLength2(p);
  b = -2*r*r*p.y;
  c = r*r*(r*r-p.x*p.x);
  d = sqrt(b*b-4*a*c);
  res1->y = (-b+d)/(2*a);
  res2->y = (-b-d)/(2*a);
  res1->x = (r*r-res1->y*p.y)/p.x;
  res2->x = (r*r-res2->y*p.y)/p.x;
}

/* 円cに，pから接線を引いて，接線と円の交点を2つ求める */
/* 制約: pは円の外 */
void pntPointToCircleTangential(pnt p,circle c,pnt *res1,pnt *res2){
  pntPointToCircleTangentialEasy( pntMinus(p,c.c), c.r, res1, res2 );
  *res1 = pntPlus(*res1,c.c);
  *res2 = pntPlus(*res2,c.c);
}







/* 点p から 直線t へ引いた垂線の足を返す */
pnt pntPointLinePerpendicular(pnt p,line t){
  double k; pnt ab,ap;
  ab=pntMinus(t.b, t.a);  ap=pntMinus(p, t.a);
  k=pntInnerProduct(ab,ap)/pntLength2(ab);
  return pntPlus( t.a, pntMultipleDouble(ab,k) );
}

/* 点p の 直線t に対して対称な点を求める */
pnt pntSymmetricPointWithLine(pnt p,line t){
  pnt go = pntPointLinePerpendicular(p,t);
  go=pntMinus(go,p); return pntPlus( p,pntMultipleDouble(go,2) );
}

double distancePntSegment(pnt p,line t){
  double d1,d2;
  pnt c = pntPointLinePerpendicular(p,t);
  if( isPntOnSegment(c,t) ) return pntDistance(p,c);
  d1 = pntDistance(p,t.a); d2 = pntDistance(p,t.b);
  if(d1 > d2) return d2; return d1;
}

double distancePntLine(pnt p,line t){
  return pntDistance(p,pntPointLinePerpendicular(p,t));
}




/* 速度vで動く点が直線に辿り着くまでの時間 (マイナスもあり) */
/* 戻り値 0=辿り着かない， 1=辿り着く, 2=恒にその直線上を動く */
/* return 1; のとき double res = 辿り着く時間 pnt reachPoint = 辿り着いた場所 */
int getTimeMovingPntReachLine(pnt p,pnt v,line s,double *res, pnt *reachPoint){
  pnt lineVector = pntNormalize(pntMinus(s.b,s.a));
  double inner = pntInnerProduct(lineVector,v);
  double dist  = distancePntLine(p,s);
  pnt vv = pntMinus(v,pntMultipleDouble(lineVector,inner));

  if(pntSign(vv)==0){
    if(doubleSign(dist)==0) return 2;
    return 0;
  }

  *res = dist / pntLength(vv);
  *reachPoint = pntPlus(p,pntMultipleDouble(v,*res));
  if( !isPntOnLine(*reachPoint, s) ){
    (*res) *= -1;
    *reachPoint = pntPlus(p,pntMultipleDouble(v,*res));
  }
  return 1;
}




/* 長さap : bp = s : tを満たす点pの集合(円)を返す 制約: s!=t */
circle pntSetDivisionPoint(pnt a,double s,pnt b,double t){
  pnt r1,r2,ab; circle res;
  ab=pntMinus(b,a);
  r1 = pntPlus(a,pntMultipleDouble(ab,s/(s+t)));
  r2 = pntPlus(a,pntMultipleDouble(ab,s/(s-t)));
  res.c = pntMultipleDouble(pntPlus(r1,r2),0.5); res.r=pntDistance(r1,r2)/2;
  return res;
}




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

/* 三角形の符号付面積の2倍 */
double pntAreaOfTriangle2(pnt p1,pnt p2,pnt p3){
  double x1,x2,y1,y2;
  x1=p2.x-p1.x; x2=p3.x-p1.x;
  y1=p2.y-p1.y; y2=p3.y-p1.y;
  return x1*y2-x2*y1;
}

/* 符号付面積の符号を返す                   */
/* p1,p2の直線の左にp3がある場合，戻り値=1  */
/* p1,p2の直線の右にp3がある場合，戻り値=-1 */
/* p1,p2,p3が一直線上にある場合， 戻り値=0  */
int pntSignAreaOfTriangle(pnt p1,pnt p2,pnt p3){
  return doubleSign( pntAreaOfTriangle2(p1,p2,p3) );
}




/* 点の進行方向 */
/* 1,-1は符号付き面積の符号と同じ */
/* 2 : c -- a -- b */
/* -2: a -- b -- c */
/* 0 : その他      */
int pntCCW(pnt a,pnt b,pnt c){
  double tmp;
  b=pntMinus(b,a); c=pntMinus(c,a);
  tmp = pntOuterProduct(b,c);
  if( doubleSign(tmp) ) return doubleSign( tmp );
  if( doubleSign( pntInnerProduct(b,c) ) == -1 ) return 2;
  if( doubleSign( pntLength(c)-pntLength(b) ) == 1 ) return -2;
  return 0;
}

/* convex hull (Andrew's Monotone Chain) */
/* 制約: size >= 3, pはsorted (x座標について) */
/* return 凸包の頂点数 */
/* たぶん，直線上の中点を含まない → pntCCW(res[res_size-2],res[res_size-1],p[i])<=0 */
/* たぶん，直線上の中点を含める   → pntCCW(res[res_size-2],res[res_size-1],p[i])==-1 */
int pntConvexHull(pnt p[],int size,pnt res[]){
  int i,res_size=0,t;
  for(i=0;i<size;res[res_size++]=p[i++])    while(res_size>=2 && pntCCW(res[res_size-2],res[res_size-1],p[i])<=0) res_size--;
  t=res_size;
  for(i=size-2;i>=0;res[res_size++]=p[i--]) while(res_size> t && pntCCW(res[res_size-2],res[res_size-1],p[i])<=0) res_size--;
  return res_size-1;
}




/* 2直線の交点を求める (交わる点が無限大の場合の判定は未実装) */
/* 戻り値: 交点の数 無限大の場合も0を返す                     */
/* 後の仕様予定: return 2が無限大の場合                       */
int pntIntersectionLineLine(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double r = (p4.y-p3.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p4.x-p3.x);
  if( doubleSign(r)==0 ) return 0;
  res->x = (p3.x*p4.y-p3.y*p4.x)*(p2.x-p1.x)-(p1.x*p2.y-p1.y*p2.x)*(p4.x-p3.x);
  res->y = (p3.y*p4.x-p3.x*p4.y)*(p2.y-p1.y)-(p1.y*p2.x-p1.x*p2.y)*(p4.y-p3.y);
  res->x /= r; res->y /= -r; return 1;
}

/* s=line, t=segment */
int pntIntersectionLineSegment(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double x1,x2,y1,y2;
  if(pntIntersectionLineLine(s,t,res)!=1) return 0;
  x1=MIN(p3.x,p4.x)-EPS; x2=MAX(p3.x,p4.x)+EPS;
  y1=MIN(p3.y,p4.y)-EPS; y2=MAX(p3.y,p4.y)+EPS;
  if(res->x < x1 || x2 < res->x || res->y < y1 || y2 < res->y) return 0;
  if(pntIsEqual(*res,p3)) return 1;
  if(pntIsEqual(*res,p4)) return 1;
  return 2;
}

/* 2線分の交点を求める (2線分が平行の場合，問答無用で交わらないと判断してしまう) */
/* 戻り値: 2=交わる, 1=端も線分に含めると交わる, 0=交わらない                    */
int pntIntersectionSegmentSegment(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double x1,x2,y1,y2;
  if(pntIntersectionLineLine(s,t,res)!=1) return 0;
  x1=MIN(p1.x,p2.x)-EPS; x2=MAX(p1.x,p2.x)+EPS;
  y1=MIN(p1.y,p2.y)-EPS; y2=MAX(p1.y,p2.y)+EPS;
  if(res->x < x1 || x2 < res->x || res->y < y1 || y2 < res->y) return 0;
  x1=MIN(p3.x,p4.x)-EPS; x2=MAX(p3.x,p4.x)+EPS;
  y1=MIN(p3.y,p4.y)-EPS; y2=MAX(p3.y,p4.y)+EPS;
  if(res->x < x1 || x2 < res->x || res->y < y1 || y2 < res->y) return 0;
  if(pntIsEqual(*res,p1)) return 1;
  if(pntIsEqual(*res,p2)) return 1;
  if(pntIsEqual(*res,p3)) return 1;
  if(pntIsEqual(*res,p4)) return 1;
  return 2;
}


/* 2円の共通部分の面積を求める */
double pntAreaOfIntersectionCircleCircle(circle s,circle t){
  int k; pnt p1,p2,q1,q2; double th1,th2;
  if( doubleSign(s.r-t.r)==-1 ) return pntAreaOfIntersectionCircleCircle(t,s);
  k = pntIntersectionCircleCircle(s,t,&p1,&p2);
  if(k<=1 || k==3){
    if( pntDistance(s.c,t.c) < s.r ) return PI*t.r*t.r;
    return 0;
  }
  q1=pntMinus(p1,s.c); q2=pntMinus(p2,s.c);
  th1 = atan2(q1.y,q1.x) - atan2(q2.y,q2.x);
  while(th1 < -EPS)     th1 += 2*PI;
  while(th1 > 2*PI-EPS) th1 -= 2*PI;
  if(th1 > PI) th1 = 2*PI - th1;
  q1=pntMinus(p1,t.c); q2=pntMinus(p2,t.c);
  th2 = atan2(q1.y,q1.x) - atan2(q2.y,q2.x);
  while(th2 < -EPS)     th2 += 2*PI;
  while(th2 > 2*PI-EPS) th2 -= 2*PI;
  if(th2 > PI) th2 = 2*PI - th2;

  if( pntSignAreaOfTriangle(p1,p2,s.c)==pntSignAreaOfTriangle(p1,p2,t.c) ) th2 = 2*PI - th2;
  return s.r*s.r*(th1-sin(th1))/2 + t.r*t.r*(th2-sin(th2))/2;
}







/* poly内部かつ直線lsの左側からなる領域の凸多角形を返す */
/* 制約: polyは凸                                          */
int pntConvexPolygonCut(pnt poly[],int ps,line ls,pnt res[]){
  int i, size=0, n=ps; pnt p, p1=ls.a, p2=ls.b;
  poly[n]=poly[0];
  rep(i,n){
    if(pntSignAreaOfTriangle(p1,p2,poly[i])>=0){
      res[size++]=poly[i];
      if(size>=2 && pntIsEqual(res[size-2],res[size-1])) size--;
    }
    if(pntSignAreaOfTriangle(p1,p2,poly[i])*pntSignAreaOfTriangle(p1,p2,poly[i+1])==-1){
      pntIntersectionLineLine(ls,pntToLine(poly[i],poly[i+1]),&p); res[size++]=p;
      if(size>=2 && pntIsEqual(res[size-2],res[size-1])) size--;
    }
  }
  if(size && pntIsEqual(res[0],res[size-1])) size--;
  res[size]=res[0];
  return size;
}

/* 垂直2等分線を返す */
/* 制約: a != b      */
/* 返す線の向きは ab を反時計回りに90度回転した向き */
line perpendicularBisectorOfSegment(pnt a,pnt b){
  line res; pnt mid, dir;
  mid = pntMultipleDouble(pntPlus(a,b),0.5);
  dir = pntRatationEasy( pntMinus(b,a), PI/2 );
  res.a = pntMinus(mid,dir); res.b = pntPlus(mid,dir);
  return res;
}



/* 多角形の符号付き面積を求める */
double areaOfPolygon(pnt poly[],int ps){
  int i; double res=0;
  poly[ps]=poly[0];
  rep(i,ps) res+=poly[i].x*poly[i+1].y-poly[i].y*poly[i+1].x;
  return res/2;
}






/* 2円の共通接線のうち共通外接線を2つ求める (円が包含されてないこと) ttp://www.phoenix-c.or.jp/~tokioka/2circle/2circle.html */
void cal_1(circle a,circle b,line *s,line *t){
  double th,d,S,L,alpha;

  th = pntArgument(pntMinus(b.c,a.c));
  d = pntDistance(a.c,b.c);
  S = a.r; L= b.r;

  alpha = (L-S)/d;

  if(doubleSign(alpha)==0){
    s->a = pntGenerator(0,S);
    s->b = pntGenerator(1,S);
    t->a = pntGenerator(0,-S);
    t->b = pntGenerator(1,-S);
  } else if(doubleSign(alpha-1)==0){
    s->a = t->a = pntGenerator(S,0);
    s->b = t->b = pntGenerator(S,1);
  } else {
    s->a = t->a = pntGenerator(-S/alpha,0);
    s->b = pntGenerator(-S/alpha + 1,  alpha/sqrt(1-alpha*alpha));
    t->b = pntGenerator(-S/alpha + 1, -alpha/sqrt(1-alpha*alpha));
  }

  s->a = pntRatationEasy(s->a,th);
  s->b = pntRatationEasy(s->b,th);
  t->a = pntRatationEasy(t->a,th);
  t->b = pntRatationEasy(t->b,th);

  s->a = pntPlus(s->a, a.c);
  s->b = pntPlus(s->b, a.c);
  t->a = pntPlus(t->a, a.c);
  t->b = pntPlus(t->b, a.c);
}


void cal_2(circle a,circle b,line *s,line *t){
  double th,d,S,L,beta;

  th = pntArgument(pntMinus(b.c,a.c));
  d = pntDistance(a.c,b.c);
  S = a.r; L= b.r;

  beta = (L+S)/d;

  if(doubleSign(beta-1)==0){
    s->a = t->a = pntGenerator(S,0);
    s->b = t->b = pntGenerator(S,1);
  } else {
    s->a = t->a = pntGenerator(S/beta,0);
    s->b = pntGenerator(S/beta + 1,  beta/sqrt(1-beta*beta));
    t->b = pntGenerator(S/beta + 1, -beta/sqrt(1-beta*beta));
  }

  s->a = pntRatationEasy(s->a,th);
  s->b = pntRatationEasy(s->b,th);
  t->a = pntRatationEasy(t->a,th);
  t->b = pntRatationEasy(t->b,th);

  s->a = pntPlus(s->a, a.c);
  s->b = pntPlus(s->b, a.c);
  t->a = pntPlus(t->a, a.c);
  t->b = pntPlus(t->b, a.c);
}




/* 三角形abcのaの反対側にある傍接円(傍心と半径)を返す */
circle pntExcircleOfTriangle(pnt a,pnt b,pnt c){
  line ln1,ln2;
  pnt s,t;
  circle res;

  s=pntNormalize(pntMinus(b,a)); t=pntNormalize(pntMinus(c,b));
  ln1.a=b;
  ln1.b=pntPlus(b,pntPlus(s,t));
  
  s=pntNormalize(pntMinus(c,a)); t=pntNormalize(pntMinus(b,c));
  ln2.a=c;
  ln2.b=pntPlus(c,pntPlus(s,t));

  pntIntersectionLineLine(ln1,ln2,&res.c);
  s = pntPointLinePerpendicular(res.c,pntToLine(b,c));
  res.r = pntDistance(res.c,s);

  return res;
}

void getTriangleFromLength(double A,double B,double C,pnt *a,pnt *b,pnt *c){
  double th = (A*A+B*B-C*C)/(2*A*B);

  if(th<-1) th=-1; if(th>1) th=1;
  *a = pntGenerator(0,0);
  *b = pntGenerator(A,0);
  *c = pntPolar(B,acos(th));
}



int pntIsInTriangle(pnt p,pnt a,pnt b,pnt c){
  int x,y;
  int fg1=1, fg2=1;

  x=pntSignAreaOfTriangle(a,b,p); y=pntSignAreaOfTriangle(a,b,c);
  if(x==0) fg1=0;
  if(x && x!=y) fg1=fg2=0;
  
  x=pntSignAreaOfTriangle(b,c,p); y=pntSignAreaOfTriangle(b,c,a);
  if(x==0) fg1=0;
  if(x && x!=y) fg1=fg2=0;
  
  x=pntSignAreaOfTriangle(c,a,p); y=pntSignAreaOfTriangle(c,a,b);
  if(x==0) fg1=0;
  if(x && x!=y) fg1=fg2=0;

  return fg1+fg2;
}




/* 3点を通る円を返す */
/* 成功したらfg=1, 失敗したらfg=0 */
circle getCircleFromThreePoint(pnt a,pnt b,pnt c,int *fg){
  line A,B;
  circle res;

  A = perpendicularBisectorOfSegment(a,b);
  B = perpendicularBisectorOfSegment(a,c);

  *fg = pntIntersectionLineLine(A,B,&res.c);
  if(*fg) res.r = pntDistance(a,res.c);
  return res;
}


void intReverse(int d[],int size){int a=0,b=size-1,t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}
int intNextPermutation(int d[],int size){int i,j,k;for(k=size-2;k>=0;k--)if(d[k]<d[k+1])break;if(k<0){intReverse(d,size);return 0;}for(i=size-1;;i--)if(d[i]>d[k])break;j=d[i],d[i]=d[k],d[k]=j;intReverse(d+k+1,size-k-1);return 1;}


int main(){
  int i,j,k,l,m,n;
  int size, count = 0;
  
  pnt in[200], poly[200];
  int ind[200];
  int res[100]; double mxarea, area;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest %d\n",size);
    scanf("%d",&n);
    rep(i,n) scanf("%lf%lf",&in[i].x,&in[i].y);

    rep(i,n) ind[i] = i;
    mxarea = -1;
    do{
      if(ind[0]!=0) break;

      k = 0;
      rep(i,n) rep(j,n) if(i<j) if(k<2){
        line s, t;
        s = pntToLine(in[ind[i]], in[ind[(i+1)%n]]);
        t = pntToLine(in[ind[j]], in[ind[(j+1)%n]]);
        k = pntIntersectionSegmentSegment(s,t,in+199);
        if(isPntOnSegment(t.a, s)==2) k = 2;
        if(isPntOnSegment(t.b, s)==2) k = 2;
        if(isPntOnSegment(s.a, t)==2) k = 2;
        if(isPntOnSegment(s.b, t)==2) k = 2;
      }
      if(k==2) continue;

      rep(i,n) poly[i] = in[ind[i]];
      area = areaOfPolygon(poly, n);
      if(mxarea < area){
        mxarea = area;
        rep(i,n) res[i] = ind[i];
      }
    }while(intNextPermutation(ind,n));


    printf("Case #%d:",++count);
    rep(i,n) printf(" %d", res[i]); puts("");
  }

  return 0;
}
