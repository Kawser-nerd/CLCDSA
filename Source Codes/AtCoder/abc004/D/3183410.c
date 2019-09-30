#include <stdio.h>

int main(void)
{
	int r, g, b, ro, bo, go, rw, gw, bw, rs, bs, rc=0, gc=0, bc=0, t1, t2, op;
	scanf("%d%d%d", &r, &g, &b);

	if (r > b) {
		int tmp = r;
		r = b;
		b = tmp;
	}

	ro = (r-1) % 2;
	go = (g-1) % 2;
	bo = (b-1) % 2;
	rw = (r-1) / 2;
	gw = (g-1) / 2;
	bw = (b-1) / 2;
	rs = rw+gw+go-99;
	bs = gw+bw-99;

	op = (rw+1)*(rw+ro) + (gw+1)*(gw+go) + (bw+1)*(bw+bo);

	if (bs > 0 || rs > 0) {
		if (rs < 0) {
			while (gc < -rs && gc+bc < bs) {
				if (gc < gw)
					t2 = go+2*gc+1;
				else
					t2 = g; 

				if ((t1=bo+2*bc+1) > t2) {
					++gc;
					op += t2;
				}
				else {
					++bc;
					op += t1;
				}
			}
		}
		else if (rs > 0) {
			while (rc < rs) {
				if (rc < rw) {
					op += ro+2*rc+1;
					rc++;
				}
				else {
					op += r;
					rc++;
				}
			}
		}
		while (gc+bc < bs) {
			if (gc < gw)
				t2 = go+2*gc+1;
			else
				t2 = g; 

			if (bc < bw)
				t1 = bo+2*bc+1;
			else
				t1 = b;

			if (rc < rw)
				t2 += ro+2*rc+1;
			else
				t2 += r;

			if (t1 > t2) {
				gc++;
				rc++;
				op += t2;
			}
			else {
				bc++;
				op += t1;
			}
		}
	}

	printf("%d\n", op);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &r, &g, &b);
  ^