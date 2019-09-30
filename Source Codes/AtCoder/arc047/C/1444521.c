#include <stdio.h>
#include <stdlib.h>

#define int long long
#define datatype int

typedef struct {
	datatype *dat;
	int N; //2????
	datatype (*f)(datatype x, datatype y);//??
	datatype e;//??????
}seg_tree;

//??n?segment_tree???
seg_tree *make_seg_tree(int n, datatype (*f)(datatype x, datatype y), datatype e){
	seg_tree *t = (seg_tree *)malloc(sizeof(seg_tree));
	int N, i;
	for(N = 1; N < n; N *= 2){}
	t->dat = (datatype *)malloc(sizeof(datatype) * (2 * N - 1));
	for(i = 0; i < 2 * N - 1; i++){
		t->dat[i] = e;
	}
	t->N = N;
	t->f = f;
	t->e = e;
	return t;
}

//i?????x?????
void update(int i, datatype val, seg_tree *t){
	i += t->N - 1;
	t->dat[i] = val;
	while(i > 0){
		i = (i - 1) / 2;
		t->dat[i] = (t->f)(t->dat[2 * i + 1], t->dat[2 * i + 2]);
	}
}

datatype query_sub(int a, int b, int k, int l, int r, seg_tree *t){
	if(r <= a || b <= l){
		return t->e;
	}
	else if(a <= l && r <= b){
		return t->dat[k];
	}
	else{
		int h = (l + r) / 2;
		datatype vl = query_sub(a, b, 2 * k + 1, l, h, t);
		datatype vr = query_sub(a, b, 2 * k + 2, h, r, t);
		return (t->f)(vl, vr);
	}
}

//[a, b)????????????????
datatype query(int a, int b, seg_tree *t){
	return query_sub(a, b, 0, 0, t->N, t);
}

int sum(int a, int b){
	return a + b;
}

signed main(){
	int N, K, i, s, u, n, l, h, r;
	scanf("%lld%lld", &N, &K);
	seg_tree *t = make_seg_tree(N + 1, sum, 0);
	for(i = 1; i <= N; i++){
		update(i, 1, t);
	}
	for(i = 1, s = 1, n = N; i <= N; i++, n--){
		u = (s * n - 1) / K + 1;
		l = 0; r = N + 1;
		while(r - l > 1){
			h = (l + r) / 2;
			if(query(0, h, t) >= u){
				r = h;
			}
			else{
				l = h;
			}
		}
		printf("%d\n", l);
		update(l, 0, t);
		s = s * n - K * (u - 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:82:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%d\n", l);
          ^
./Main.c:65:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^