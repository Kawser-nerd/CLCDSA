#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

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

double ppDistance(const Point &a,const Point &b)
{
	return dist(a.x,a.y,b.x,b.y);
}
int getIntersect(const Circle &A,const Circle &B,Point &P,Point &Q)
{
	double X1=A.x,Y1=A.y,X2=B.x,Y2=B.y;
	double R1=A.r,R2=B.r;
	double dst=dist(X1,Y1,X2,Y2);
	if (dst>R1+R2+eps || dst<fabs(R1-R2)-eps) return 0;
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


const int maxn=40+5;

int n;
Point C[maxn];
double R[maxn];
double key;
int m;
Point P[maxn*maxn];

bool checkIt()
{
	for (int i=0;i<n;i++)
		if (compare(R[i],key)>0)
			return false;
	m=0;
	for (int i=0;i<n;i++)
		P[m++]=C[i];
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			Circle C1(P[i].x,P[i].y,key-R[i]);
			Circle C2(P[j].x,P[j].y,key-R[j]);
			Point P1,P2;
			int cnt=getIntersect(C1,C2,P1,P2);
			if (cnt>=1) P[m++]=P1;
			if (cnt>=2) P[m++]=P2;
		}
	for (int i=0;i<m;i++)
		for (int j=i;j<m;j++)
		{
			Point P1=P[i],P2=P[j];
			bool isGood=true;
			for (int k=0;k<n;k++)
				if (compare(ppDistance(P1,P[k]),key-R[k])>0
				 && compare(ppDistance(P2,P[k]),key-R[k])>0)
				{
					isGood=false;
					break;
				}
			if (isGood) return true;
		}
	return false;
}
int main()
{
//	freopen("D.in","r",stdin);
//	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%lf%lf%lf",&C[i].x,&C[i].y,&R[i]);
		double H=0,T=10000;
		if (caseId<=15) continue;
		for (int step=0;step<100;step++)
		{
			if (fabs(H-T)<=1e-8) break;
			key=(H+T)/2.0;
			if (checkIt())
				T=key;
			else
				H=key;
		}
		printf("Case #%d: %.12lf\n",caseId,T);
		fflush(stdout);
	}
	return 0;
}