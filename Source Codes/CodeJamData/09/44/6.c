#include <stdio.h>
#include <math.h>

int xp[5];
int yp[5];
int rp[5];

#define RR(i, j, k) rr = (sqrt((xp[i]-xp[j])*(xp[i]-xp[j])+(yp[i]-yp[j])*(yp[i]-yp[j]))+rp[i]+rp[j])*0.5; if (rp[k] > rr) rr = rp[k]; if (r > rr) r = rr;

void main(void)
{
	int t, ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int n, i;
		double r = 1e7;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d %d %d", xp+i, yp+i, rp+i);
		}
		if (n == 1) {
			r = rp[0];
		} else if (n == 2) {
			r = rp[0] < rp[1] ? rp[1] : rp[0];
		} else if (n == 3) {
			double rr;
			RR(0, 1, 2);
			RR(0, 2, 1);
			RR(1, 2, 0);		
		}
		printf("Case #%d: %0.7lf\n", ti, r);
	}
}
