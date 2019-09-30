#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))



int main(void){
	/* === input paramater === */
	int l;
	int x;
	int y;
	int s;
	int d;

	/* === operate paramater === */
	double right;
	double left;
	/* === input === */
	scanf("%d%d%d%d%d",&l,&x,&y,&s,&d);
	if(x>=y){
		if(d>=s){
			printf("%.10lf\n",((double)d-s)/(x+y));
		}else{
			printf("%.10lf\n", ((double)d + l - s)/(x+y));
		}		
	}else{
		if(d>=s){
			right = ((double)d-s)/(x+y);
			left = ((double)s + l - d)/(y-x);
			printf("%.10lf\n", min(right,left));
		}else{
			right = ((double)d + l - s)/(x + y);
			left = ((double)s - d)/(y - x);
			printf("%.10lf\n", min(right,left));
		}
	}


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d",&l,&x,&y,&s,&d);
  ^