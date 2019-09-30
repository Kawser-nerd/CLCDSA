#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define int long long

typedef struct {
	int x;
	int y;
}pos;

typedef struct {
	int N;
	pos *ps;
}convex_hull;

//(x, y)??????
signed compare_ch(const void *a_sub, const void *b_sub){
	pos a = *(pos *)a_sub, b = *(pos *)b_sub;
	if(a.x != b.x){
		return a.x - b.x;
	}
	else{
		return a.y - b.y;
	}
}

//a??b??????
pos vec(pos a, pos b){
	pos ans;
	ans.x = b.x - a.x;
	ans.y = b.y - a.y;
	return ans;
}

//???z??
int cross_product_z(pos a, pos b){
	return a.x * b.y - a.y * b.x;
}

double arg(pos a, pos b){
	if(a.y == b.y){
		return M_PI / 2;
	}
	else{
		return atan((double)(a.x - b.x) / (b.y - a.y));
	}
}

double ABS(double x){
//	printf("x = %.12lf\n", x);
	x = x >= 0 ? x : x + M_PI;
	return x;
}

convex_hull *build_convex_hull(int N, pos *ps){
	int i, j;
	pos *psub = (pos *)malloc(sizeof(pos) * N);
	for(i = 0; i < N; i++){
		psub[i] = ps[i];
	}
	qsort(psub, N, sizeof(pos), compare_ch);
	convex_hull *ch = (convex_hull *)malloc(sizeof(convex_hull));
	ch->ps = (pos *)malloc(sizeof(pos) * (N + 1));
	ch->ps[0] = psub[0];
	pos a, b;
	for(i = 1, j = 1; i < N;){
		if(j <= 1){
			ch->ps[j] = psub[i];
			i++;
			j++;
		}
		else{
			a = vec(ch->ps[j - 1], ch->ps[j - 2]);
			b = vec(ch->ps[j - 1], psub[i]);
			if(cross_product_z(a, b) >= 0){
				j--;
			}
			else{
				ch->ps[j] = psub[i];
				i++;
				j++;
			}
		}
	}
	int h = j - 1;
	for(i = N - 1; i >= 0;){
		if(j <= h + 1){
			ch->ps[j] = psub[i];
			i--;
			j++;
		}
		else{
			a = vec(ch->ps[j - 1], ch->ps[j - 2]);
			b = vec(ch->ps[j - 1], psub[i]);
			if(cross_product_z(a, b) >= 0){
				j--;
			}
			else{
				ch->ps[j] = psub[i];
				i--;
				j++;
			}
		}
	}
	ch->N = j - 1;
	return ch;
}

signed main(){
	int N, i, j, k;
	scanf("%lld", &N);
	pos *ps = (pos *)malloc(sizeof(pos) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &ps[i].x, &ps[i].y);
	}
	convex_hull *ch = build_convex_hull(N, ps);
	for(i = 0; i < N; i++){
		k = -1;
		for(j = 0; j < ch->N; j++){
			if(ps[i].x == ch->ps[j].x && ps[i].y == ch->ps[j].y){
				k = j;
				break;
			}
		}
		if(k == -1){
			printf("0\n");
		}
		else{
			if(ch->N == 2){
				printf("0.5\n");
			}
			else{
				printf("%.12lf\n", ABS(arg(ch->ps[k], ch->ps[(k + 1) % ch->N]) - arg(ch->ps[(k - 1 + ch->N) % ch->N], ch->ps[k])) / (2 * M_PI));
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:111:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:114:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &ps[i].x, &ps[i].y);
   ^