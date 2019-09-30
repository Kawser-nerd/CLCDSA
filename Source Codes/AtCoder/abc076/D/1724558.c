#include <stdio.h>
#include <math.h>

#define EPS 1e-10
#define INF 1000000000

typedef struct {
	int x1, y1, x2, y2;
} Line;

Line line[102][3];

int rel_s_s(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double *x, double *y) {
	const double dn = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);

	if (fabs(dn) < EPS)
		return 2;
	else {
		const double s = ((x3 - x1) * (y4 - y3) - (x4 - x3) * (y3 - y1)) / dn;
		const double t = ((x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1)) / dn;

		if (-EPS < s && s < 1.0 + EPS && -EPS < t && t < 1.0 + EPS) {
			*x = x1 + s * (x2 - x1);
			*y = y1 + s * (y2 - y1);
			return 0;
		} else
			return 6;
	}
}

int main(void) {
	int n, t[103], v[102];

	scanf("%d", &n);

	t[0] = -INF;
	t[1] = 0;
	t[n + 2] = INF;
	v[0] = 0;
	v[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		t[i + 1] = t[i] + tmp;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", v + i);

	for (int i = 0; i <= n + 1; i++) {
		line[i][0] = (Line){0, v[i] + t[i], t[i], v[i]};
		line[i][1] = (Line){t[i], v[i], t[i + 1], v[i]};
		line[i][2] = (Line){t[i + 1], v[i], t[n + 1], v[i] + t[n + 1] - t[i + 1]};
	}

	double cur_x = 0, cur_y = 0;
	int cur_idx = 0, cur_type = 2;
	double sum = 0;
	while (cur_x < t[n + 1]) {
		const Line l = line[cur_idx][cur_type];
		double x, y;
		double min_x = l.x2, min_y = l.y2;
		int min_idx = -1, min_type = -1;

		if (cur_type == 0)
			cur_type = 1;
		else if (cur_type == 1) {
			for (int i = cur_idx + 1; i <= n + 1; i++) {
				const Line m = line[i][0];
				int rel = rel_s_s(l.x1, l.y1, l.x2, l.y2, m.x1, m.y1, m.x2, m.y2, &x, &y);
				if (rel == 0)
					if (x < min_x) {
						min_x = x;
						min_idx = i;
					}
			}

			if (min_x < l.x2) {
				cur_idx = min_idx;
				cur_type = 0;
			} else
				cur_type = 2;
		} else {
			for (int type = 0; type <= 1; type++)
				for (int i = cur_idx + 1; i <= n + 1; i++) {
					const Line m = line[i][type];
					int rel = rel_s_s(l.x1, l.y1, l.x2, l.y2, m.x1, m.y1, m.x2, m.y2, &x, &y);
					if (rel == 0)
						if (x < min_x) {
							min_x = x;
							min_y = y;
							min_idx = i;
							min_type = type;
						}
				}

			cur_idx = min_idx;
			cur_type = min_type;
		}

		sum += (cur_y + min_y) * (min_x - cur_x) / 2.;

		cur_x = min_x;
		cur_y = min_y;
	}

	printf("%f\n", sum);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:43:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &tmp);
   ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", v + i);
   ^