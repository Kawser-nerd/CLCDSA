#include <stdio.h>
#define min(x,y) (x) < (y) ? (x) : (y)

int l, x, y, s, d;

int main()
{
	scanf("%d %d %d %d %d",&l,&x,&y,&s,&d);
	int fast = d - s; if (fast < 0)fast += l;
	int slow = l - fast;
	double ans = min((double)fast / (x+y),(y>x)?(double)slow / (y-x):1234567890);
	printf("%.10lf\n",ans);
	return 0;
}