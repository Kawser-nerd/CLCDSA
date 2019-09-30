#include <stdio.h>
#include <stdlib.h>

#define inf (1e9 + 7)

typedef struct {
	double x;
	double y;
	double c;
}pos;

double max(double a, double b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

double min(double a, double b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int can_achieve(pos *p, int N, double h){
	int i;
	double Xmax = inf, Xmin = -inf, Ymax = inf, Ymin = -inf, xmax, xmin, ymax, ymin;
	for(i = 0; i < N; i++){
		xmax = p[i].x + h / p[i].c;
		xmin = p[i].x - h / p[i].c;
		ymax = p[i].y + h / p[i].c;
		ymin = p[i].y - h / p[i].c;
		if(xmax < Xmin || Xmax < xmin || ymax < Ymin || Ymax < ymin){
			return 0;
		}
		Xmax = min(xmax, Xmax);
		Xmin = max(xmin, Xmin);
		Ymax = min(ymax, Ymax);
		Ymin = max(ymin, Ymin);
	}
	return 1;
}

int main(){
	int N, x, y, c, i;
	scanf("%d", &N);
	pos *tak = (pos *)malloc(sizeof(pos) * N);
	for(i = 0; i < N; i++){
		scanf("%d%d%d", &x, &y, &c);
		tak[i].x = (double)x;
		tak[i].y = (double)y;
		tak[i].c = (double)c;
	}
	double l = 0, h, r = inf;
	while(r - l > 1e-6){
		h = (l + r) / 2;
		if(can_achieve(tak, N, h) == 1){
			r = h;
		}
		else{
			l = h;
		}
	}
	printf("%.9f\n", r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:51:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &x, &y, &c);
   ^