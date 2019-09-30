#include <stdio.h>
#include <vector>
#define eps 1e-06
using namespace std;
struct POINT {
	double x, y;
	POINT(double _x = 0.0, double _y = 0.0) {x = _x; y = _y;}
};
int W, G;
vector<POINT> L, U, d;
double area()
{
	double r = 0.0;

	for (int i = 1; i+1 < d.size(); i++)
		r += (d[i].x-d[0].x)*(d[i+1].y-d[0].y) - (d[i].y-d[0].y)*(d[i+1].x-d[0].x);
	if (r < 0) r = -r;
	return r/2;
}
double help(double x)
{
	int i;

	d.clear();
	for (i = 0; i+1 < L.size(); i++) {
		d.push_back(L[i]);
		if (L[i].x-eps < x && x < L[i+1].x+eps) {
			d.push_back(POINT(x,L[i].y+(L[i+1].y-L[i].y)/(L[i+1].x-L[i].x)*(x-L[i].x)));
			break;
		}
	}
	for (i = 0; i+1 < U.size(); i++) {
		if (U[i].x-eps < x && x < U[i+1].x+eps) {
			d.push_back(POINT(x,U[i].y+(U[i+1].y-U[i].y)/(U[i+1].x-U[i].x)*(x-U[i].x)));
			break;
		}
	}
	for (; i >= 0; i--) {
		d.push_back(U[i]);
	}
	return area();
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, T, i, j, k;
	POINT p;
	double r;
	double s, e, m;

	scanf("%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n",t);
		scanf("%d%d%d%d",&W,&i,&j,&G);
		L.clear();
		for (k = 0; k < i; k++) {
			scanf("%lf%lf",&p.x,&p.y);
			L.push_back(p);
		}
		U.clear();
		for (k = 0; k < j; k++) {
			scanf("%lf%lf",&p.x,&p.y);
			U.push_back(p);
		}
		d.clear();
		for (i = 0; i < L.size(); i++) d.push_back(L[i]);
		for (i = U.size()-1; i >= 0; i--) d.push_back(U[i]);
		r = area();
		k = 0;
		for (i = 0; i < G-1; i++) {
			for (s = 0, e = W; e-s > eps;) {
				m = (s+e)/2;
				if (help(m) >= r/G*(i+1)) e = m;
				else s = m;
			}
			printf("%.10lf\n",e);
		}
	}
	return 0;
}