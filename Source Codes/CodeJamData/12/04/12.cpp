#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	if(a < 0) a = -a;
	if(b < 0) b = -b;
	while(a)
	{
		b %= a;
		swap(a, b);
	}
	return b;
}


int h,w,d;
char dat[32][32];
int sx, sy;

const double eps = 1e-9;


double getdist(double x, double y, int dx, int dy, double total)
{
	double minLen = 0;
	bool isDestroy = false;
	bool isSelf = false;

	for(;;)
	{
		double nkx;
		if(dx > 0) nkx = (floor(x + 1 + eps) - x) / dx;
		else if(dx < 0) nkx = (ceil(x - 1 - eps) - x) / dx;
		else nkx = 1e60;
		double nky;
		if(dy > 0) nky = (floor(y + 1 + eps) - y) / dy;
		else if(dy < 0) nky = (ceil(y - 1 - eps) - y) / dy;
		else nky = 1e60;

		double nkG;
		if(dy != 0) nkG = (sy + 0.5 - y) / dy;
		if(dx != 0) nkG = (sx + 0.5 - x) / dx;

		if(nkG > eps && nkG < min(nkx,nky))
		{
			if( (fabs((x + nkG*dx) - (sx + 0.5)) < eps) &&
				(fabs((y + nkG*dy) - (sy + 0.5)) < eps))
			{
				minLen += nkG * sqrt((double)(dx*dx + dy*dy));
				isSelf = true;
				break;
			}
		}

		if(nkx + eps < nky)
		{
			minLen += nkx * sqrt((double)(dx*dx + dy*dy));
			x = x + dx * nkx;
			y = y + dy * nkx;

			if( (dx > 0 && dat[(int)y][(int)(x+eps    )] == '#') ||
				(dx < 0 && dat[(int)y][(int)(x+eps - 1)] == '#') )
			{
				dx = -dx;
				break;
			}
		}
		else if(nkx > nky + eps)
		{
			minLen += nky * sqrt((double)(dx*dx + dy*dy));
			x = x + dx * nky;
			y = y + dy * nky;

			if( (dy > 0 && dat[(int)(y + eps    )][(int)x] == '#') ||
				(dy < 0 && dat[(int)(y + eps - 1)][(int)x] == '#') )
			{
				dy = -dy;
				break;
			}
		}
		else
		{
			minLen += nkx * sqrt((double)(dx*dx + dy*dy));
			x = x + dx * nkx;
			y = y + dy * nky;

			int c1 = (int)(x+eps-1);
			int c2 = (int)(x+eps);
			int r1 = (int)(y+eps-1);
			int r2 = (int)(y+eps);

			if(dx < 0) swap(c1,c2);
			if(dy < 0) swap(r1,r2);
			char center = dat[r2][c2];
			char side1 = dat[r2][c1];
			char side2 = dat[r1][c2];
			if(center == '#' && side1 == '#' && side2 == '#')
			{
				dx = -dx;
				dy = -dy;
				break;
			}
			if(center == '#' && side1 != '#' && side2 != '#')
			{
				isDestroy = true;
				break;
			}
			if(center == '#' && side1 == '#' && side2 != '#')
			{
				dy = -dy;
				break;
			}
			if(center == '#' && side1 != '#' && side2 == '#')
			{
				dx = -dx;
				break;
			}
		}
	}

	if(isDestroy || total + minLen > d + 1e-9) return d * 2;
	if(isSelf) return total + minLen;
	return getdist(x, y, dx, dy, total + minLen);
}

bool simulate(int dx, int dy)
{
	double res = getdist(sx + 0.5, sy + 0.5, dx, dy, 0);
	if(res <= d + 1e-9)
	{
		return true;
	}
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		scanf("%d%d%d",&h,&w,&d);
		for(int i = 0; i < h; i ++)
		{
			scanf("%s",dat[i]);
			for(int j = 0;j < w; j ++)
			{
				if(dat[i][j] == 'X')
				{
					sy = i;
					sx = j;
				}
			}
		}

		int ans = 0;

		for(int dx = -d; dx <= d; dx ++)
		{
			for(int dy = -d; dy <= d; dy ++)
			{
				if(dx == 0 && dy == 0) continue;
				if(gcd(dx,dy) != 1) continue;

				if(simulate(dx, dy))
				{
					ans ++;
				}
			}
		}

		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}