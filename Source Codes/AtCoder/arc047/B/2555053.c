#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int ABS(int a){
	return a >= 0 ? a : -a;
}

int distance(int x1, int y1, int x2, int y2){
	return max(ABS(x1 - x2), ABS(y1 - y2));
}

signed main(){
	int N, x_sub, y_sub, i, xmax = -inf, xmin = inf, ymax = -inf, ymin = inf;
	scanf("%lld", &N);
	int *x = (int *)malloc(sizeof(int) * N);
	int *y = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &x_sub, &y_sub);
		x[i] = x_sub + y_sub;
		y[i] = x_sub - y_sub;
		xmax = max(xmax, x[i]);
		xmin = min(xmin, x[i]);
		ymax = max(ymax, y[i]);
		ymin = min(ymin, y[i]);
	}
	int D, Px, Py, f;
	D = max(xmax - xmin, ymax - ymin);
	Px = xmin + D / 2;
	Py = ymin + D / 2;
	f = 1;
	for(i = 0; i < N; i++){
		if(distance(Px, Py, x[i], y[i]) != D / 2){
			f = 0;
			break;
		}
	}
	if(f == 1){
		printf("%lld %lld\n", (Px + Py) / 2, (Px - Py) / 2);
		return 0;
	}
	Px = xmax - D / 2;
	Py = ymin + D / 2;
	f = 1;
	for(i = 0; i < N; i++){
		if(distance(Px, Py, x[i], y[i]) != D / 2){
			f = 0;
			break;
		}
	}
	if(f == 1){
		printf("%lld %lld\n", (Px + Py) / 2, (Px - Py) / 2);
		return 0;
	}
	Px = xmin + D / 2;
	Py = ymax - D / 2;
	f = 1;
	for(i = 0; i < N; i++){
		if(distance(Px, Py, x[i], y[i]) != D / 2){
			f = 0;
			break;
		}
	}
	if(f == 1){
		printf("%lld %lld\n", (Px + Py) / 2, (Px - Py) / 2);
		return 0;
	}
	Px = xmax - D / 2;
	Py = ymax - D / 2;
	f = 1;
	for(i = 0; i < N; i++){
		if(distance(Px, Py, x[i], y[i]) != D / 2){
			f = 0;
			break;
		}
	}
	if(f == 1){
		printf("%lld %lld\n", (Px + Py) / 2, (Px - Py) / 2);
		return 0;
	}
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &x_sub, &y_sub);
   ^