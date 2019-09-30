#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

double ri2;
double gsqrhalf;
double kk;

double calc2(double x, double y, double g)
{
	//return gsqrhalf;
	double x2 = x+g, y2 = y+g;
	double xe = x2*x2+y*y;
	double ye = y2*y2+x*x;
	double xi, yi, xi2, yi2;
	double ang1, ang2;
	if (x*x+y*y >= ri2) return 0.0;
	if (x2*x2+y2*y2 <= ri2) return g*g;
	if (ri2 <= xe)
		if (ri2 <= ye)
		{
			xi = sqrt(ri2-y*y);
			yi = sqrt(ri2-x*x);
			ang1 = atan(y/xi);
			ang2 = atan(yi/x);
			return kk*(ang2-ang1)-(y*(xi-x)+x*(yi-y))/2;
		}
		else // ri2 > ye
		{
			xi = sqrt(ri2-y*y);
			xi2= sqrt(ri2-y2*y2);
			ang1 = atan(y/xi);
			ang2 = atan(y2/xi2);
			return kk*(ang2-ang1)-(y*(xi-x)+x*g-y2*(xi2-x))/2;
		}
	else
		if (ri2 <= ye)
		{
			yi = sqrt(ri2-x*x);
			yi2 = sqrt(ri2-x2*x2);
			ang1 = atan(yi2/x2);
			ang2 = atan(yi/x);
			return kk*(ang2-ang1)-(x*(yi-y)+y*g-x2*(yi2-y))/2;
		}
		else // ri2 > ye
		{
			xi2= sqrt(ri2-y2*y2);
			yi2 = sqrt(ri2-x2*x2);
			ang1 = atan(yi2/x2);
			ang2 = atan(y2/xi2);
			return kk*(ang2-ang1)-((x+y)*g-x2*(yi2-y)-y2*(xi2-x))/2;
		}
}

double calc(double f, double R, double t, double r, double g)
{
	double pi = acos(0.0)*2;
	if (g <= f*2) return 1.0;
	double ri = R-t-f;
	ri2 = ri*ri;
	if (ri <= 0) return 1.0;
	g -= f*2;
	r += f;

	double w = r*2+g;

/*	double x, y;
	int cnt = 0, hit = 0;
	double th1 = ri*ri/R/R;
	while (cnt < 10000000)
	{
		int xx = rand();
		int yy = rand();
		if (xx*xx+yy*yy > (int)RAND_MAX*RAND_MAX) continue;
		x = 1.0*xx/RAND_MAX;
		y = 1.0*yy/RAND_MAX;
		double q = x*x+y*y;
		//if (q > 1.0) continue;
		cnt++;
		if (q >= th1)
		{
			hit++;
			continue;
		}
		x -= r;
		int i = x/w;
		x -= i*w;
		if (x >= g) continue;
		y -= r;
		int j = y/w;
		y -= j*w;
		if (y < g) hit++;
	}

	return 1.0*hit/cnt;*/

	gsqrhalf = g*g/2;
	kk = ri*ri/2;
	double sum = 0.0;
	int cnt = 0;

	int n = (sqrt(ri2-r*r)-r)/w+1;

	for (int i = 0; i < n; i++)
	{
		double x = r+w*i;
		double d = ri2-x*x;
		if (d <= 0) continue;
		d = sqrt(d)-r;
		if (d <= 0) continue;
		int k = d/w;
		cnt += k;
		double y = r+w*k;
		if (sqr(x+g)+sqr(y+g) <= ri2) cnt++;
		else 
		{
			int k2 = 0;
			double d;
			d = ri2-sqr(x+g);
			if (d >= 0)
			{
				d = sqrt(d)-r;
				if (d >= 0)
					k2 = d/w;
			}
			cnt += (k2-k);
			for (int j = k; j >= k2; j--)
			{
				sum += calc2(x, y, g);
				y -= w;
			}
		}
	}

	return 1.0-(sum+cnt*g*g)*4/(pi*R*R);
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int i,j;
		double R, r, t, f, g;
		fin >> f >> R >> t >> r >> g;
		double ans = calc(f, R, t, r, g);
		fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
