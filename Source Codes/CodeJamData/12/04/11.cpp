#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

const double eps = 1e-7;

int T,n,m,d;
double ssx,ssy,sx,sy;
char map[60][60],cmap[60][60];



int upnum(double x)
{
	return (int)round(x+0.5-eps);
}

double dis(double x, double y)
{
	return sqrt(x*x+y*y);
}

int gcd(int x, int y)
{
	if (y==0) return x;
		else return gcd(y, x%y);
}

int walk(double dx, double dy)
{
	memcpy(map,cmap,sizeof(map));
	double left = d; double nx = sx = ssx,ny = sy = ssy; bool flag = false;
	while (left>=0)
	{
		if (dx<0)
		{
			dx = -dx;
			for (int i=0; i < n/2; i++) 
				for (int j=0; j<m; j++) swap(map[i][j], map[n-i-1][j]);
			nx = (double)n - nx;
			sx = (double)n - sx;
		}
		
		if (dy<0)
		{
			dy = -dy;
			for (int i=0; i < n; i++) 
				for (int j=0; j<m/2; j++) swap(map[i][j], map[i][m-j-1]);
			ny = (double)m - ny;
			sy = (double)m - sy;
		}
		
		
		
		int tempy = upnum(ny), tempx = upnum(nx);
		
		while ((double)tempx - nx < eps) tempx ++;
		while ((double)tempy - ny < eps) tempy ++;	
		
		
		if (sx+eps>nx && sy+eps>ny && abs((sx-nx)*dy - (sy-ny)*dx)<eps && flag)
		{
			if (sy-eps < tempy && sx-eps < tempx)
			{
				left-=dis(sx-nx,sy-ny);
				if (left >-eps) return 1;
				else return 0;
			}
		}
		flag = true;
		//y
		if (((double)tempy - ny)*dx+eps < ((double)tempx - nx)*dy)
		{
			double tt = ((double)tempy - ny)/dy;
			ny = tempy; nx +=  dx*tt; left-=dis(dx,dy)*tt;
			if (map[tempx-1][tempy] == '#') dy = -dy;
		}
		//x
		else
		if (((double)tempy - ny)*dx-eps > ((double)tempx - nx)*dy)
		{
			double tt = ((double)tempx - nx)/dx;
			nx = tempx; ny +=  dy*tt; left-=dis(dx,dy)*tt;
			if (map[tempx][tempy-1] == '#') dx = -dx;
		}
		//center
		else
		{
			left-=dis(tempx-nx,tempy-ny); nx = tempx; ny = tempy; 
			if (map[tempx][tempy-1] != '#' && map[tempx-1][tempy] != '#' && map[tempx][tempy] == '#') return 0;
			if (map[tempx][tempy-1] == '#' && map[tempx][tempy] == '#') dx = -dx;
			if (map[tempx-1][tempy] == '#' && map[tempx][tempy] == '#') dy = -dy;
		}
	}
	return 0;
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d\n",&T);
	for (int casenum=1; casenum<=T; casenum++)
	{
		scanf("%d %d %d\n",&n,&m,&d);
		int ans = 0;
		for (int i=0; i<n; i++) gets(cmap[i]);
		for (int i=0; i<n;i++)
			for (int j=0; j<m; j++)
				if (cmap[i][j] == 'X') ssx=i+0.5, ssy=j+0.5;
		for (int dx=0; dx<=d+1; dx++)
			for (int dy=0; dy<=d+1; dy++)
				if (dx+dy!=0 && gcd(dx,dy)==1)
				{
					ans += walk(dx,dy);
					if (dx!=0) ans += walk(-dx,dy);
					if (dy!=0) ans += walk(dx,-dy);
					if (dx!=0 && dy!=0) ans += walk(-dx,-dy);
				}
		printf("Case #%d: %d\n", casenum, ans);
	}
}
