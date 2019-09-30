#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)

const double eps=1e-11;
template<class T> inline T sqr(T x){return x*x;}
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}
int compare(double a,double b){return(fabs(a-b)<=eps)?0:((a<b)?-1:1);}

struct Point
{
	double x,y;
	Point(double _x=0,double _y=0)
	{
		x=_x;
		y=_y;
	}
	int compareTo(const Point &other)
	{
		int c=compare(x,other.x);
		if (c!=0) return c;
		return compare(y,other.y);
	}
};
struct Line
{
	double a,b,c;
	Line(double _a=0,double _b=0,double _c=0)
	{
		a=_a;
		b=_b;
		c=_c;
		double d=sqrt(sqr(a)+sqr(b));
		a/=d;
		b/=d;
		c/=d;
		if (a<-eps || a<=eps && b<0) a=-a,b=-b,c=-c;
	}
	int compareTo(const Line &other)
	{
		int c1=compare(a,other.a);
		if (c1!=0) return c1;
		int c2=compare(b,other.b);
		if (c2!=0) return c2;
		return compare(c,other.c);
	}
};
struct Circle
{
	double x,y,r;
	Circle(double _x=0,double _y=0,double _r=0)
	{
		x=_x;
		y=_y;
		r=_r;
	}
	int compareTo(const Circle &other)
	{
		int c1=compare(x,other.x);
		if (c1!=0) return c1;
		int c2=compare(y,other.y);
		if (c2!=0) return c2;
		return compare(r,other.r);
	}
};

Line getLineByTwoPoints(const Point &p1,const Point &p2)
{
	double a=+(p1.y-p2.y);
	double b=-(p1.x-p2.x);
	double c=p1.x*p2.y-p2.x*p1.y;
	return Line(a,b,c);
}
double ppDistance(const Point &a,const Point &b)
{
	return dist(a.x,a.y,b.x,b.y);
}
double plDistance(const Point &p,const Line &l)
{
	return fabs(l.a*p.x+l.b*p.y+l.c)/sqrt(sqr(l.a)+sqr(l.b));
}
double cross(const Point &a,const Point &b,const Point &c)
{
	return cross(a.x,a.y,b.x,b.y,c.x,c.y);
}
int crossop(const Point &a,const Point &b,const Point &c)
{
	return compare(cross(a,b,c),0);
}
bool isMiddle(double a,double m,double b)
{
	return fabs(a-m)<=eps || fabs(b-m)<=eps || (a<m)!=(b<m);
}
bool isMiddle(const Point &a,const Point &m,const Point &b)
{
	return crossop(a,m,b)==0 && isMiddle(a.x,m.x,b.x) && isMiddle(a.y,m.y,b.y);
}
bool isTouchIntersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return isMiddle(a,c,d) || isMiddle(a,d,b) || isMiddle(c,a,d) || isMiddle(c,b,d);
}
bool isCrossIntersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return (crossop(a,b,c)*crossop(a,b,d)<0 && crossop(c,d,a)*crossop(c,d,b)<0);
}
bool isIntersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return isCrossIntersect(a,b,c,d) || isTouchIntersect(a,b,c,d);
}
double psDistance(const Point &p,const Point &a,const Point &b)
{
	double sab=sqr(a.x-b.x)+sqr(a.y-b.y);
	double spa=sqr(p.x-a.x)+sqr(p.y-a.y);
	double spb=sqr(p.x-b.x)+sqr(p.y-b.y);
	if (fabs(spa-spb)<=sab)
		return fabs(cross(p,a,b))/sqrt(sab);
	else
		return sqrt(min(spa,spb));
}
int getIntersect(const Line &A,const Line &B,Point &P)
{
	double a1=A.a;
	double b1=A.b;
	double c1=A.c;
	double a2=B.a;
	double b2=B.b;
	double c2=B.c;
	double t=a1*b2-a2*b1;
	if (fabs(t)<=eps) return 0;
	double X0=+(b1*c2-b2*c1)/t;
	double Y0=-(a1*c2-a2*c1)/t;
	P.x=X0;
	P.y=Y0;
	return 1;
}
int getIntersect(const Line &A,const Circle &C,Point &P,Point &Q)
{
	double a=A.a;
	double b=A.b;
	double c=A.c;
	double CX=C.x,CY=C.y;
	double R=C.r;
	//ax+by+c=0
	//(+by+c+aCX)^2+(ay-aCY)^2=(aR)^2
	double x1,y1,x2,y2;
	if (fabs(a)>fabs(b))
	{
		double A=sqr(a)+sqr(b);
		double B=2.0*b*(c+a*CX)-2.0*sqr(a)*CY;
		double C=sqr(c+a*CX)+sqr(a)*(sqr(CY)-sqr(R));
		double delta=sqr(B)-4*A*C;
		if (delta<-eps) return 0;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		P.x=x1;P.y=y1;
		Q.x=x2;Q.y=y2;
	}
	else
	{
		swap(a,b);swap(CX,CY);
		double A=sqr(a)+sqr(b);
		double B=2.0*b*(c+a*CX)-2.0*sqr(a)*CY;
		double C=sqr(c+a*CX)+sqr(a)*(sqr(CY)-sqr(R));
		double delta=sqr(B)-4*A*C;
		if (delta<-eps) return 0;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		swap(x1,y1);swap(x2,y2);
		swap(a,b);swap(CX,CY);
		P.x=x1;P.y=y1;
		Q.x=x2;Q.y=y2;
	}
	return 2;
}
int getIntersect(const Circle &A,const Circle &B,Point &P,Point &Q)
{
	double X1=A.x,Y1=A.y,X2=B.x,Y2=B.y;
	double R1=A.r,R2=B.r;
	double dst=dist(X1,Y1,X2,Y2);
	if (dst>R1+R2+eps || dst<fabs(R1-R2)-eps) return 0;
	if (dst<=eps) return 0;
	//(x-X1)^2+(y-Y1)^2=sqr(R1)=x^2-2*X1*x+X1^2+y^2-2*Y1*y+Y1^2 (1)
	//(x-X2)^2+(y-Y2)^2=sqr(R2)=x^2-2*X2*x+X2^2+y^2-2*Y2*y+Y2^2 (2)
	//(2)-(1):  sqr(R2)-sqr(R1)=2*(X1-X2)*x+2*(Y1-Y2)*y+sqr(X2)-sqr(X1)+sqr(Y2)-sqr(Y1)
	//	 :  (X1-X2)*x+(Y1-Y2)*y-(sqr(X1)-sqr(X2)+sqr(Y1)-sqr(Y2)-sqr(R1)+sqr(R2))/2.0;
	double a=X1-X2;
	double b=Y1-Y2;
	double c=-(a*(X1+X2)+b*(Y1+Y2)-sqr(R1)+sqr(R2))/2.0;
	double CX=X1,CY=Y1;
	//ax+by+c=0
	//(+by+c+aCX)^2+(ay-aCY)^2=(aR)^2
	double x1,y1,x2,y2;
	if (fabs(a)>fabs(b))
	{
		double A=sqr(a)+sqr(b);
		double B=2.0*b*(c+a*CX)-2.0*sqr(a)*CY;
		double C=sqr(c+a*CX)+sqr(a)*(sqr(CY)-sqr(R1));
		double delta=sqr(B)-4*A*C;
		if (delta<-eps) return 0;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		P.x=x1;P.y=y1;
		Q.x=x2;Q.y=y2;
	}
	else
	{
		swap(a,b);swap(CX,CY);
		double A=sqr(a)+sqr(b);
		double B=2.0*b*(c+a*CX)-2.0*sqr(a)*CY;
		double C=sqr(c+a*CX)+sqr(a)*(sqr(CY)-sqr(R1));
		double delta=sqr(B)-4*A*C;
		if (delta<-eps) return 0;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		swap(x1,y1);swap(x2,y2);
		swap(a,b);swap(CX,CY);
		P.x=x1;P.y=y1;
		Q.x=x2;Q.y=y2;
	}
	return 2;
}

const int maxsize=1000+5;
const double pi=acos(-1.0);

int nLine;
int nCircle;
Line lines[maxsize];
Circle circles[maxsize];
Point s0,s1;
int n;
Circle pillars[maxsize];
double R[4];

double toLeft(int id,double x)
{
	double d=fabs(x-circles[id].x);
	double p=acos(d/circles[id].r);
	if (x>=circles[id].x)
	{
		return sqr(circles[id].r)*p/2.0+circles[id].r*d*sin(p)/2.0
			  +sqr(circles[id].r)*(pi-p-p)/2.0;
	}
	return sqr(circles[id].r)*p/2.0-circles[id].r*d*sin(p)/2.0;
}
double toLeft(int id,double tx,double x0,double y0)
{
	double base=circles[id].y*(tx-(circles[id].x-circles[id].r));
	if (y0>=circles[id].y)
		return base+toLeft(id,tx);
	else
		return base-toLeft(id,tx);
}
double toLeft(double sx,double tx,double keyx,double keyy,int id)
{
	if (id<100000000)
	{
		return keyy*(tx-sx);
	}
	id-=100000000;
	return toLeft(id,tx,keyx,keyy)-toLeft(id,sx,keyx,keyy);
}
int main()
{
/*
	freopen("F.in","w",stdout);
	printf("1000\n");
	for (int caseId=1;caseId<=1000;caseId++)
	{
		s0.x=rand()%99+1;
		s0.y=rand()%99+1;
		while (1)
		{
			s1.x=rand()%99+1;
			s1.y=rand()%99+1;
			if (s0.compareTo(s1)!=0)
				break;
		}
		printf("%.0lf %.0lf\n",s0.x,s0.y);
		printf("%.0lf %.0lf\n",s1.x,s1.y);
		int n=rand()%51;
		printf("%d\n",n);
		for (int i=0;i<n;i++)
		{
			while(1)
			{
				pillars[i].x=rand()%99+1;
				pillars[i].y=rand()%99+1;
				pillars[i].r=rand()%49+1;
				bool isGood=true;
				Point key(pillars[i].x,pillars[i].y);
				if (ppDistance(key,s0)<=pillars[i].r+1e-5)
					isGood=false;
				if (ppDistance(key,s1)<=pillars[i].r+1e-5)
					isGood=false;
				for (int k=0;k<i-1;k++)
					if (ppDistance(key,Point(pillars[k].x,pillars[k].y))<=pillars[i].r+pillars[k].r+1e-5)
						isGood=false;
				if (isGood) break;
			}
			printf("%.0lf %.0lf %.0lf\n",pillars[i].x,pillars[i].y,pillars[i].r);
		}
	}
	return 0;
*/
//	freopen("F.in","r",stdin);
//	freopen("F-small-attempt0.in","r",stdin);freopen("F-small-attempt0_2.out","w",stdout);
//	freopen("F-small-attempt1.in","r",stdin);freopen("F-small-attempt1.out","w",stdout);
//	freopen("F-small-attempt2.in","r",stdin);freopen("F-small-attempt2.out","w",stdout);
	freopen("F-large.in","r",stdin);freopen("F-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	int n;
	double maxDelta=0;
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d:\n",caseId);
		scanf("%lf%lf",&s0.x,&s0.y);
		scanf("%lf%lf",&s1.x,&s1.y);
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%lf%lf%lf",&pillars[i].x,&pillars[i].y,&pillars[i].r);
		nLine=0;
		nCircle=0;
		for (int i=0;i<n;i++)
			circles[nCircle++]=pillars[i];
		lines[nLine++]=Line(1,0,0);
		lines[nLine++]=Line(0,1,0);
		lines[nLine++]=Line(1,0,-100);
		lines[nLine++]=Line(0,1,-100);
		for (int i=0;i<n;i++)
			for (int s=0;s<2;s++)
			{
				Point p=(s==0)?s0:s1;
				Point c=Point(pillars[i].x,pillars[i].y);
				double r=pillars[i].r;
				double d=ppDistance(p,c);
				double p0=atan2(p.y-c.y,p.x-c.x);
				double dp=acos(r/d);
				double p1=p0-dp;
				double p2=p0+dp;
				Point r1=Point(c.x+r*cos(p1),c.y+r*sin(p1));
				Point r2=Point(c.x+r*cos(p2),c.y+r*sin(p2));
				lines[nLine++]=getLineByTwoPoints(p,r1);
				lines[nLine++]=getLineByTwoPoints(p,r2);
			}
		vector<double> keys;
		for (int i=0;i<nLine;i++)
			for (int j=i+1;j<nLine;j++)
			{
				Point p;
				int c=getIntersect(lines[i],lines[j],p);
				if (c>0)
					keys.push_back(p.x);
			}
		for (int i=0;i<nLine;i++)
			for (int j=0;j<nCircle;j++)
			{
				Point p[2];
				int c=getIntersect(lines[i],circles[j],p[0],p[1]);
				for (int k=0;k<c;k++)
					keys.push_back(p[k].x);
			}
		for (int i=0;i<nCircle;i++)
		{
			keys.push_back(circles[i].x);
			keys.push_back(circles[i].x-circles[i].r);
			keys.push_back(circles[i].x+circles[i].r);
		}
		R[0]=R[1]=R[2]=R[3]=0;
		sort(keys.begin(),keys.end());
		for (int k=0;k+1<SIZE(keys);k++)
		{
			double startx=keys[k];
			double endx=keys[k+1];
			double keyx=(startx+endx)/2.0;
			if (keyx<0 || keyx>100.0) continue;
			if (fabs(startx-endx)<=eps) continue;
			Line keyLine(1,0,-keyx);
			vector<pair<double,int> > lsty;
			for (int i=0;i<nLine;i++)
			{
				Point p;
				int c=getIntersect(keyLine,lines[i],p);
				if (c==0) continue;
				double y=p.y;
				if (y>=-eps && y<=100+eps) lsty.push_back(MP(y,i));
			}
			for (int i=0;i<nCircle;i++)
			{
				Point p[2];
				int c=getIntersect(keyLine,circles[i],p[0],p[1]);
				for (int j=0;j<c;j++)
				{
					double y=p[j].y;
					if (y>=-eps && y<=100+eps) lsty.push_back(MP(y,100000000+i));
				}
			}
			sort(lsty.begin(),lsty.end());
			for (int i=0;i+1<SIZE(lsty);i++)
			{
				double keyy=(lsty[i].first+lsty[i+1].first)/2.0;
				Point keyPoint(keyx,keyy);
				bool isGood=true;
				for (int j=0;isGood && j<nCircle;j++)
					if (ppDistance(keyPoint,Point(circles[j].x,circles[j].y))<circles[j].r)
						isGood=false;
				if (!isGood) continue;
				int state=0;
				for (int s=0;s<2;s++)
				{
					Point other=(s==0)?s0:s1;
					bool isBad=false;
					for (int j=0;!isBad && j<nCircle;j++)
					{
						Point p[2];
						Line L=getLineByTwoPoints(keyPoint,other);
						int c=getIntersect(L,circles[j],p[0],p[1]);
						for (int v=0;v<c;v++)
						{
							Point d=p[v];
							if (isMiddle(keyPoint,d,other))
								isBad=true;
						}
					}
					if (!isBad)
						state|=(1<<s);
				}
				R[state]-=toLeft(startx,endx,keyx,lsty[i].first,lsty[i].second);
				R[state]+=toLeft(startx,endx,keyx,lsty[i+1].first,lsty[i+1].second);
			}			
		}
		for (int i=0;i<4;i++)
			printf("%.18lf\n",R[i]);
		fflush(stdout);
/*
		double R2[4];
		memset(R2,0,sizeof(R2));
		for (int i=0;i<1000;i++)
			for (int j=0;j<1000;j++)
			{
				double keyx=(i+0.5)/10.0;
				double keyy=(j+0.5)/10.0;
				Point keyPoint(keyx,keyy);
				bool isGood=true;
				for (int j=0;isGood && j<nCircle;j++)
					if (ppDistance(keyPoint,Point(circles[j].x,circles[j].y))<circles[j].r)
						isGood=false;
				if (!isGood) continue;
				int state=0;
				for (int s=0;s<2;s++)
				{
					Point other=(s==0)?s0:s1;
					bool isBad=false;
					for (int j=0;!isBad && j<nCircle;j++)
					{
						Point p[2];
						Line L=getLineByTwoPoints(keyPoint,other);
						int c=getIntersect(L,circles[j],p[0],p[1]);
						for (int v=0;v<c;v++)
						{
							Point d=p[v];
							if (isMiddle(keyPoint,d,other))
								isBad=true;
						}
					}
					if (!isBad)
						state|=(1<<s);
				}
				R2[state]+=0.01;				
			}
		for (int i=0;i<4;i++)
			printf("%.18lf\n",R2[i]);
		for (int i=0;i<4;i++)
		{
			double t=fabs(R[i]-R2[i]);
			if (t>maxDelta)
				maxDelta=t;
		}
		printf("MaxDelta = %.6lf\n",maxDelta);
*/
	}
	return 0;
}