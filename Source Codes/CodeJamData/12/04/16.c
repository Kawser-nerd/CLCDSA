#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int ncase = -1;

int h, w, d;

void flush()
{
	while(getchar()!='\n');
}

char p[30][30];
int line,col;

void solve(int icase)
{
	printf("Case #%d: ", icase + 1);

	int res = 0, i, j, k;

	scanf("%d%d%d", &h, &w, &d);
	flush();
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			p[i][j] = getchar();
			if(p[i][j] == 'X')
			{
				line = i;
				col = j;
			}
		}
		flush();
	}

	int left, right, up, down;
	
	left = right = col;
	up = down = line;
	
	while(p[line][left]!='#')
		left--;
	while(p[line][right]!='#')
		right++;
	while(p[up][col]!='#')
		up--;
	while(p[down][col]!='#')
		down++;

	int d2l = 2*(col-left) - 1;
	int d2r = 2*(right-col) - 1;
	int d2u = 2*(line-up) - 1;
	int d2d = 2*(down-line) - 1;
	
	if(d2l <= d)	res++;
	if(d2r <= d)	res++;
	if(d2u <= d)	res++;
	if(d2d <= d)	res++;
	
	int dv = d2u+d2d;
	int dh = d2l+d2r;
	int ve = (d/dv + 1)*2;
	int ho = (d/dh + 1)*2;
	int dsq = d*d;
	
	int c = 0;
	int x[2000];
	int y[2000];
	int xx, yy;
	// ul
	for(i = 0; i < ho; i++)
	{
		xx = dh * ((i+1)/2);
		if(i%2 == 0)
			xx += d2l;
		for(j = 0; j < ve; j++)
		{
			yy = dv * ((j+1)/2);
			if(j%2 == 0)
				yy += d2u;
			
			int sq = xx * xx + yy * yy;
			if(sq > dsq)
				break;
			for(k=0; k < c; k++)
			{
				if(x[k]*yy == xx*y[k])
					break;
			}
			if(k==c)
			{
				x[c] = xx;
				y[c] = yy;
				c++;
			}
		}
	}	
	res += c;

	// ur
	c = 0;
	for(i = 0; i < ho; i++)
	{
		xx = dh * ((i+1)/2);
		if(i%2 == 0)
			xx += d2r;
		for(j = 0; j < ve; j++)
		{
			yy = dv * ((j+1)/2);
			if(j%2 == 0)
				yy += d2u;
			
			int sq = xx * xx + yy * yy;
			if(sq > dsq)
				break;
			for(k=0; k < c; k++)
			{
				if(x[k]*yy == xx*y[k])
					break;
			}
			if(k==c)
			{
				x[c] = xx;
				y[c] = yy;
				c++;
			}
		}
	}	
	res += c;
	
	// dl
	c = 0;
	for(i = 0; i < ho; i++)
	{
		xx = dh * ((i+1)/2);
		if(i%2 == 0)
			xx += d2l;
		for(j = 0; j < ve; j++)
		{
			yy = dv * ((j+1)/2);
			if(j%2 == 0)
				yy += d2d;
			
			int sq = xx * xx + yy * yy;
			if(sq > dsq)
				break;
			for(k=0; k < c; k++)
			{
				if(x[k]*yy == xx*y[k])
					break;
			}
			if(k==c)
			{
				x[c] = xx;
				y[c] = yy;
				c++;
			}
		}
	}	
	res += c;
	
	// dr
	c = 0;
	for(i = 0; i < ho; i++)
	{
		xx = dh * ((i+1)/2);
		if(i%2 == 0)
			xx += d2r;
		for(j = 0; j < ve; j++)
		{
			yy = dv * ((j+1)/2);
			if(j%2 == 0)
				yy += d2d;
			
			int sq = xx * xx + yy * yy;
			if(sq > dsq)
				break;
			for(k=0; k < c; k++)
			{
				if(x[k]*yy == xx*y[k])
					break;
			}
			if(k==c)
			{
				x[c] = xx;
				y[c] = yy;
				c++;
			}
		}
	}
	res += c;
	
	printf("%d\n", res);
}

int main()
{
	scanf("%d", &ncase);
	flush();
	
	int icase;
	for(icase = 0; icase < ncase; icase++)
		solve(icase);
}