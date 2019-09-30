#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool inside(double R, double x, double y)
{
	return x*x+y*y<=R*R;
}

double gettriarea(double x1, double y1, double x2, double y2)
{
	return fabs(x1*y2-x2*y1)/2.0;
}
double circrect(double R, double x1, double y1, double s)
{
	if(!inside(R,x1,y1))
		return 0;
	if(inside(R, x1+s, y1+s))
		return s*s;
	if(!inside(R, x1, y1+s))
	{
		if(!inside(R, x1+s, y1))
		{
			double yint = sqrt(R*R-x1*x1);
			double xint = sqrt(R*R-y1*y1);
			double ang = fabs(atan2(yint, x1)-atan2(y1, xint));
			double area = R*R*ang/2;
			area-=gettriarea(xint, y1, x1, y1) + gettriarea(x1,y1,x1,yint);
			return area;
		}
		else
		{
			double yint1 = sqrt(R*R-x1*x1);
			double yint2 = sqrt(R*R-(x1+s)*(x1+s));
			double ang = fabs(atan2(yint1, x1)-atan2(yint2, x1+s));
			double area = 0;
			area+=(yint2-y1)*s;
			area+=ang*R*R/2-gettriarea(x1, yint1, x1, yint2)-gettriarea(x1,yint2,x1+s,yint2);
			return area;
		}
	}
	else
	{
		if(inside(R, x1+s, y1))
		{
			double xint1 = sqrt(R*R-(y1+s)*(y1+s));
			double yint1 = sqrt(R*R-(x1+s)*(x1+s));
			double ang = fabs(atan2(y1+s, xint1)-atan2(yint1, x1+s));
			double area = 0;
			area+=s*(xint1-x1);
			area+=(x1+s-xint1)*(yint1-y1);
			area+=ang*R*R/2-gettriarea(xint1, y1+s, xint1, yint1)-gettriarea(x1+s, yint1, xint1, yint1);
			return area;
		}
		else
		{
			double xint1 = sqrt(R*R-(y1+s)*(y1+s));
			double xint2 = sqrt(R*R-y1*y1);
			double ang = fabs(atan2(y1+s, xint1) - atan2(y1, xint2));
			double area = (xint1-x1)*s;
			area+=ang*R*R/2-gettriarea(xint1, y1+s, xint1, y1)-gettriarea(xint1, y1, xint2, y1);
			return area;
		}
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int test = 0; test<T; test++)
	{
		double f, R, t, r, g;
		scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
		double totalarea = M_PI*R*R;
		double hitarea = M_PI*R*R;
		if(g-2*f>0)
		{
			double removedArea = 0;
			for(int i = 0; true; i++)
			{
				int maxj = -1;
				for(int j = 0; true; j++)
				{
					double x1 = (g+2*r)*i+r+f;
					double y1 = (g+2*r)*j+r+f;
					double a = circrect(R-t-f, x1, y1, g-2*f);
					if(a==0)
						break;
					maxj = j;
					removedArea+=a;
				}
				if(maxj==-1)
					break;
			}
			removedArea*=4;
			hitarea-=removedArea;
		}
		printf("Case #%d: %.6lf\n", test+1, hitarea/totalarea);
	}
	return 0;
}
