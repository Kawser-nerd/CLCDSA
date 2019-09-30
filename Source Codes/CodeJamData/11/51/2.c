#include "stdio.h"
#include "assert.h"

#define myabs(x) ((x) < 0 ? -(x) : (x))

double sq (double x1, double y1, double x2, double y2, double x3, double y3) {
	//fprintf (stderr, "%lf\n", x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3);
	//fprintf (stderr, "%lf\n", myabs (x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3));
	return myabs (x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3);

}

#define EPS 1e-12
double poisk (double s, double x, double y1, double y2) {
	double l = 0;
	double r = x;
	while (r - l > EPS) {
		double t = (r + l) / 2;
		double ss = t * (y1 + y1 + t / x * (y2 - y1));
		if (ss < s) l = t;
		else r = t;
	}
	return l;
}

#define MAXN 1000
int xu[MAXN], yu[MAXN], xl[MAXN], yl[MAXN];
double x1[MAXN], y1[MAXN], ss[MAXN];

int main () {
	int tn;
	scanf ("%d\n", &tn);
	int tt;
	for (tt = 0; tt < tn; tt++) {
		int w, l, u;
		scanf ("%d%d%d", &w, &l, &u);
		int G;
		scanf ("%d", &G);
		int i;
		for (i = 0; i < l; i++) 
			scanf ("%d%d", &xl[i], &yl[i]);
		for (i = 0; i < u; i++) 
			scanf ("%d%d", &xu[i], &yu[i]);
		int p1 = 0, p2 = 0;
		double x, xx, tyl, tyu, yyu, yyl;
		int cc = 0;
		while (p1 < u || p2 < l) {
			if (p1 == u || (p2 < l && xu[p1] > xl[p2])) {
				x = xl[p2];
			} else {
				x = xu[p1];
			}
			//fprintf (stderr, "%lf\n", x);
			if (p1 < u && x == xu[p1]) {
				tyu = yu[p1];
				p1++;
			}  else {
				assert (p1 > 0 && p1 < u);
				tyu = yu[p1 - 1] + (x - xu[p1 - 1]) / (xu[p1] - xu[p1 - 1]) * (yu[p1] - yu[p1 - 1]);
			}
			if (p2 < l && x == xl[p2]) {
				tyl = yl[p2];
				p2++;
			}  else {
				assert (x < xl[p2]);
				assert (p2 > 0 && p2 < l);
				tyl = yl[p2 - 1] + (x - xl[p2 - 1]) / (xl[p2] - xl[p2 - 1]) * (yl[p2] - yl[p2 - 1]);
			}
  		if (x > 0) { 
  			x1[cc] = x;
				y1[cc] = tyu - tyl;
				ss[cc] = ss[cc - 1] + (y1[cc] + y1[cc - 1]) * (x - xx);
				//ss[cc] = sq (xx, yyu, x, tyu, x, tyl) + sq (xx, yyu, x, tyl, xx, yyl);
				cc ++;
			} else {
				x1[cc] = 0;
				y1[cc] = yu[0] - yl[0];
				ss[cc] = 0;
				cc ++;
			}
			//fprintf (stderr, "> %lf %lf %lf %lf %lf\n", x1[cc - 1], ss[cc - 1], y1[cc - 1], tyu, tyl);
			xx = x;
			yyu = tyu;
			yyl = tyl;
		}
		double st = ss[cc - 1] / G;
		double s = st;
		int cur = 0;
		printf ("Case #%d:\n", tt + 1);
		for (i = 0; i < G - 1; i++) {
			while (cur < cc - 1 && ss[cur] + EPS < s) cur++;
			if (ss[cur] - EPS < s) {
				printf ("%lf\n", x1[cur]);
				s += st;
			} else {
				//fprintf (stderr, "!!\n");
				printf ("%lf\n", x1[cur - 1] + poisk (s - ss[cur - 1], x1[cur] - x1[cur - 1], y1[cur - 1], y1[cur]));
				s += st;
			}
		}
	}
	return 0;
}
