#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long

int main(int argc, char const *argv[])
{
	int w,h,n;
	int x[107],y[107],a[107],xmax,xmin,ymax,ymin;
	scanf("%d%d%d",&w,&h,&n);
	xmax = 0;	xmin = w;
	ymax = 0;	ymin = h;
	for (int i = 0; i < n; ++i)
	{
		scanf(" %d%d%d",&x[i],&y[i],&a[i]);
		if(x[i] > xmax && a[i] == 1) xmax = x[i];
		else if(x[i] < xmin && a[i] == 2) xmin = x[i];
		else if(y[i] > ymax && a[i] == 3) ymax = y[i];
		else if(y[i] < ymin && a[i] == 4) ymin = y[i];
	}
	if(xmax < xmin && ymax < ymin) printf("%d\n",(xmin - xmax) * (ymin - ymax));
	else printf("0\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&w,&h,&n);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d%d%d",&x[i],&y[i],&a[i]);
   ^