/*
???????????????????????????0??????
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ZAHYO_MAX 100

typedef struct {
	int x,y;
	int id;
} xy_t;

int qsort_comp(const void* x,const void* y) {
	const xy_t* a=(const xy_t*)x;
	const xy_t* b=(const xy_t*)y;
	if((a->x)>(b->x))return 1;
	if((a->x)<(b->x))return -1;
	if((a->y)>(b->y))return 1;
	if((a->y)<(b->y))return -1;
	return 0;
}

int th_up_n;
int th_down_n;
xy_t th_up[ZAHYO_MAX];
xy_t th_down[ZAHYO_MAX];
int totuho_count;
xy_t totuho[ZAHYO_MAX];

int zahyo_num;
xy_t zahyo[ZAHYO_MAX];

void make_totuho(void) {
	int i;
	qsort(zahyo,zahyo_num,sizeof(xy_t),qsort_comp);
	/* sita no totu-ho */
	th_down_n=1;
	th_down[0]=zahyo[0];
	for(i=1;i<zahyo_num;i++) {
		while(th_down_n>1) {
			double k1,k2;
			if(zahyo[i].x==th_down[th_down_n-1].x) {
				/* INF */
				if(zahyo[i].y<th_down[th_down_n-1].y) {
					k1=-1e+200;
				} else if(zahyo[i].y>th_down[th_down_n-1].y) {
					k1=1e+200;
				} else k1=0;
			} else {
				k1=(double)(zahyo[i].y-th_down[th_down_n-1].y)/
				   (zahyo[i].x-th_down[th_down_n-1].x);
			}
			if(th_down[th_down_n-1].x==th_down[th_down_n-2].x) {
				/* INF */
				if(th_down[th_down_n-1].y<th_down[th_down_n-2].y) {
					k2=-1e+200;
				} else if(th_down[th_down_n-1].y>th_down[th_down_n-2].y) {
					k2=1e+200;
				} else k2=0;
			} else {
				k2=(double)(th_down[th_down_n-1].y-th_down[th_down_n-2].y)/
				   (th_down[th_down_n-1].x-th_down[th_down_n-2].x);
			}
			if(k1>=k2)break;
			th_down_n--;
		}
		th_down[th_down_n]=zahyo[i];
		th_down_n++;
	}

	/* ue no totu-ho */
	th_up_n=1;
	th_up[0]=zahyo[zahyo_num-1];
	for(i=zahyo_num-2;i>=0;i--) {
		while(th_up_n>1) {
			double k1,k2;
			if(zahyo[i].x==th_up[th_up_n-1].x) {
				/* INF */
				if(zahyo[i].y<th_up[th_up_n-1].y) {
					k1=1e+200;
				} else if(zahyo[i].y>th_up[th_up_n-1].y) {
					k1=-1e+200;
				} else k1=0;
			} else {
				k1=(double)(zahyo[i].y-th_up[th_up_n-1].y)/
				   (zahyo[i].x-th_up[th_up_n-1].x);
			}
			if(th_up[th_up_n-1].x==th_up[th_up_n-2].x) {
				/* INF */
				if(th_up[th_up_n-1].y<th_up[th_up_n-2].y) {
					k2=1e+200;
				} else if(th_up[th_up_n-1].y>th_up[th_up_n-2].y) {
					k2=-1e+200;
				} else k2=0;
			} else {
				k2=(double)(th_up[th_up_n-1].y-th_up[th_up_n-2].y)/
				   (th_up[th_up_n-1].x-th_up[th_up_n-2].x);
			}
			if(k1>=k2)break;
			th_up_n--;
		}
		th_up[th_up_n]=zahyo[i];
		th_up_n++;
	}
	totuho_count=0;
	for(i=0;i<th_down_n;i++)totuho[totuho_count++]=th_down[i];
	for(i=1;i<th_up_n-1;i++)totuho[totuho_count++]=th_up[i];
}

int N;
int x[100], y[100];
double result[100];

int main(void) {
	double PI = 4.0 * atan(1);
	int i;
	if (scanf("%d", &N) != 1) return 1;
	zahyo_num = N;
	for (i = 0; i < N; i++) {
		if (scanf("%d%d", &x[i], &y[i]) != 2) return 1;
		zahyo[i].x = x[i];
		zahyo[i].y = y[i];
		zahyo[i].id = i;
	}

	make_totuho();
	for (i = 0; i < totuho_count; i++) {
		int cx = totuho[i].x, cy = totuho[i].y;
		int px = totuho[(i + totuho_count - 1) % totuho_count].x, py = totuho[(i + totuho_count - 1) % totuho_count].y;
		int nx = totuho[(i + 1) % totuho_count].x, ny = totuho[(i + 1) % totuho_count].y;

		/* ??????????? */
		double pvx = px - cx, pvy = py - cy;
		double nvx = nx - cx, nvy = ny - cy;

		double naiseki = pvx * nvx + pvy * nvy;
		double plen = sqrt(pvx * pvx + pvy * pvy);
		double nlen = sqrt(nvx * nvx + nvy * nvy);
		double cosine = naiseki / (plen * nlen);
		double angle = acos(cosine < -1 ? -1 : cosine > 1 ? 1 : cosine);

		/* printf("debug %d %d %d %f %f\n", totuho[i].x, totuho[i].y, totuho[i].id, cosine, angle); */
		/* ?????????180??????????? */
		result[totuho[i].id] = (PI - angle) / (2.0 * PI);
	}

	for (i = 0; i < N; i++) {
		printf("%.15f\n", result[i]);
	}
	return 0;
}