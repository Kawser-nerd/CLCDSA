#include <stdio.h>

double mintime[210], right[210];

int main(void)
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int c, d, i, n = 0;
		fprintf(stderr, "ti %d\n", ti);
		scanf("%d %d", &c, &d);
		for (i = 0; i < c; i++) {
			int p, v;
			double left;
			scanf("%d %d", &p, &v);
			mintime[i] = (double)(v-1)*(double)d*0.5;
			left = p-mintime[i]-d*0.5;
			right[i] = p+mintime[i]+d*0.5;
			if (i > 0) {
				if (left < right[i-1]) {
					double dist = right[i-1]-left;
//					fprintf(stderr, "dist=%g, min(i-1)-min(i)=%g\n", dist, mintime[i-1]-mintime[i]);
					if (mintime[i-1] > mintime[i]) {
						if (mintime[i-1]-mintime[i] > dist) {
							mintime[i] = mintime[i-1];
							right[i] += dist;
						} else {
							right[i] += mintime[i-1]-mintime[i];
							left += mintime[i-1]-mintime[i];
							mintime[i] = mintime[i-1];
							dist = right[i-1]-left;
							mintime[i] += dist*0.5;
							right[i] += dist*0.5;
						}
					} else {
						if (mintime[i]-mintime[i-1] < dist) {
							dist -= mintime[i]-mintime[i-1];
							mintime[i] += dist*0.5;
							right[i] += dist*0.5;
						}
					}
				} else {
					if (mintime[i-1] > mintime[i]) {
						right[i] -= mintime[i-1]-mintime[i];
						mintime[i] = mintime[i-1];
					}
				}
			}
//			fprintf(stderr, "%d: %.8lf %.8lf\n", i, mintime[i], right[i]);
		}
		printf("Case #%d: %.8lf\n", ti, mintime[c-1]);
	}
	return 0;
}
