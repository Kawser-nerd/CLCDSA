#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9 + 1)

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

typedef struct {
	int x;
	int y;
}pair;

#define datatype pair

int compare(datatype a, datatype b){
	if(a.y < b.y){
		return 1;
	}
	else if(a.y > b.y){
		return -1;
	}
	else{
		return 0;
	}
}

datatype *sort_sub(datatype *origin, int N){
	datatype *ans = (datatype *)malloc(sizeof(datatype) * N);
	if(N == 1){
		ans[0] = origin[0];
	}
	else{
		int N1 = N / 2;
		int N2 = (N + 1) / 2;
		datatype *sub1 = sort_sub(&origin[0] , N1);
		datatype *sub2 = sort_sub(&origin[N1], N2);
		int i, j, k;
		for(i = 0, j = 0, k = 0; i < N; i++){
			if((compare(sub1[j], sub2[k]) == 1 && j != N1) || (k == N2)){
				ans[i] = sub1[j];
				j++;
			}
			else{
				ans[i] = sub2[k];
				k++;
			}
		}
		free(sub1);
		free(sub2);
	}
	return ans;
}

datatype *sort(datatype *origin, int N){
	datatype *ans = sort_sub(origin, N);
	free(origin);
	return ans;
}

int main(){
	int N, i, tmp, xmax = 0, xmin = inf, ymax = 0, ymin = inf;
	scanf("%d", &N);
	pair *ball = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &ball[i].x, &ball[i].y);
		if(ball[i].x < ball[i].y){
			tmp = ball[i].x;
			ball[i].x = ball[i].y;
			ball[i].y = tmp;
		}
		if(ball[i].x > xmax){
			xmax = ball[i].x;
		}
		if(ball[i].x < xmin){
			xmin = ball[i].x;
		}
		if(ball[i].y > ymax){
			ymax = ball[i].y;
		}
		if(ball[i].y < ymin){
			ymin = ball[i].y;
		}
	}
	long long int ans1, ans2;
	ans1 = (long long int)(xmax - xmin) * (ymax - ymin);
	ball = sort(ball, N);
	int dy = ball[N - 1].y - ball[0].y, _ymax = ball[N - 1].y, _ymin = inf;
	for(i = 0; ball[i].y < _ymin && ball[i].x != xmax; i++){
		_ymax = max(ball[i].x, _ymax);
		_ymin = min(ball[i].x, _ymin);
		dy = min(_ymax - min(ball[i + 1].y, _ymin), dy);
	}
	ans2 = (long long int)(xmax - ymin) * dy;
	if(ans1 < ans2){
		printf("%lld\n", ans1);
	}
	else{
		printf("%lld\n", ans2);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:77:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:80:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &ball[i].x, &ball[i].y);
   ^