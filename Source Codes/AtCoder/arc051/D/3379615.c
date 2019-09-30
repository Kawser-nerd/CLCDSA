#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

typedef struct {
	int a;
	int b;
}line; //ax+b

typedef struct LCST_node_sub{
	line l;
	struct LCST_node_sub *left;
	struct LCST_node_sub *right;
}LCST_node;

typedef struct {
	double domain_min; //x??????
	double domain_max; //x??????
	LCST_node *root;
}LCST;

double max_double(double a, double b){
	return a >= b ? a : b;
}

double calc(double x, line l){
	return l.a * x + l.b;
}

//????[domain_min, domain_max)?Li Chao Segment Tree???
LCST *make_LCST(double domain_min, double domain_max){
	LCST *lcst = (LCST *)malloc(sizeof(LCST));
	lcst->domain_min = domain_min;
	lcst->domain_max = domain_max;
	lcst->root = NULL;
	return lcst;
}

LCST_node *add_line_LCST_sub(line l, int dmin, int dmax, LCST_node *r){
	if(r == NULL){
		LCST_node *newr;
		newr = (LCST_node *)malloc(sizeof(LCST_node));
		newr->l = l;
		newr->left = NULL;
		newr->right = NULL;
		return newr;
	}
	else{
		double dmid = (dmin + dmax) / 2;
		double sub_left = calc(dmin, l) - calc(dmin, r->l);
		double sub_right = calc(dmax, l) - calc(dmax, r->l);
		double sub_half = calc(dmid, l) - calc(dmid, r->l);
		if(sub_half > 0){
			line tmp = l;
			l = r->l;
			r->l = tmp;
			sub_left = -sub_left;
			sub_right = -sub_right;
			sub_half = -sub_half;
		}
		if((sub_left <= 0 && sub_right <= 0) || dmax - dmin < 1e-5){
			return r;
		}
		else if(sub_left <= 0){
			r->right = add_line_LCST_sub(l, dmid, dmax, r->right);
			return r;
		}
		else{
			r->left = add_line_LCST_sub(l, dmin, dmid, r->left);
			return r;
		}
	}
}

//lcst???l?????
void add_line_LCST(line l, LCST *lcst){
	lcst->root = add_line_LCST_sub(l, lcst->domain_min, lcst->domain_max, lcst->root);
}

double query_LCST_sub(double x, int dmin, int dmax, LCST_node *r){
	if(r == NULL){
		return -inf;
	}
	else{
		int dmid = (dmin + dmax) / 2;
		if(x < dmid){
			return max_double(calc(x, r->l), query_LCST_sub(x, dmin, dmid, r->left));
		}
		else{
			return max_double(calc(x, r->l), query_LCST_sub(x, dmid, dmax, r->right));
		}
	}
}

//min{l(x) | l?lcst} ????
double query_LCST(double x, LCST *lcst){
	return query_LCST_sub(x, lcst->domain_min, lcst->domain_max, lcst->root);
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int W, H, i, j;
	scanf("%lld%lld", &W, &H);
	int *a = (int *)malloc(sizeof(int) * (W + 1));
	int *a_sum = (int *)malloc(sizeof(int) * (W + 1));
	int **a_sum_max = (int **)malloc(sizeof(int *) * (W + 1));
	a_sum[0] = 0;
	for(i = 1; i <= W; i++){
		scanf("%lld", &a[i]);
		a_sum[i] = a_sum[i - 1] + a[i];
	}
	for(i = 0; i <= W; i++){
		a_sum_max[i] = (int *)malloc(sizeof(int) * (W + 1));
		for(j = 0; j <= W; j++){
			if(i < j || i == 0){
				a_sum_max[i][j] = -inf;
			}
			else{
				a_sum_max[i][j] = max(a_sum_max[i - 1][j], a_sum[i] - a_sum[i - j]);
			}
		}
	}
	int *b = (int *)malloc(sizeof(int) * (H + 1));
	int *b_sum = (int *)malloc(sizeof(int) * (H + 1));
	int **b_sum_max = (int **)malloc(sizeof(int *) * (H + 1));
	b_sum[0] = 0;
	for(i = 1; i <= H; i++){
		scanf("%lld", &b[i]);
		b_sum[i] = b_sum[i - 1] + b[i];
	}
	for(i = 0; i <= H; i++){
		b_sum_max[i] = (int *)malloc(sizeof(int) * (H + 1));
		for(j = 0; j <= H; j++){
			if(i < j || i == 0){
				b_sum_max[i][j] = -inf;
			}
			else{
				b_sum_max[i][j] = max(b_sum_max[i - 1][j], b_sum[i] - b_sum[i - j]);
			}
		}
	}
	LCST **lcsts = (LCST **)malloc(sizeof(LCST *) * (H + 1));
	for(i = 1; i <= H; i++){
		lcsts[i] = make_LCST(-100001, 100001);
		for(j = 1; j <= i; j++){
			add_line_LCST((line){j, b_sum_max[i][j]}, lcsts[i]);
		}
	}
/*	printf("a_sum_max:\n");
	for(i = 0; i <= W; i++){
		for(j = 0; j <= W; j++){
			printf("%lld ", a_sum_max[i][j]);
		}
		printf("\n");
	}
	printf("b_sum_max:\n");
	for(i = 0; i <= H; i++){
		for(j = 0; j <= H; j++){
			printf("%lld ", b_sum_max[i][j]);
		}
		printf("\n");
	}
*/	int Q, q, A, B, ans;
	double now;
	line l;
	scanf("%lld", &Q);
	for(q = 0; q < Q; q++){
		scanf("%lld%lld", &A, &B);
		ans = -inf;
		for(i = 1; i <= A; i++){
			now = i * query_LCST((double)a_sum_max[A][i] / i, lcsts[B]);
			if(now > 0){
				now += 0.5;
			}
			else{
				now -= 0.5;
			}
			ans = max(ans, (int)now);
		}
		printf("%lld\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:107:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &W, &H);
  ^
./Main.c:113:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^
./Main.c:132:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &b[i]);
   ^
./Main.c:170:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &Q);
  ^
./Main.c:172:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &A, &B);
   ^