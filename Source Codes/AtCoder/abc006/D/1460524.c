#include <stdio.h>
#include <stdlib.h>

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

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, c, i;
	scanf("%d", &N);
	seg_tree *t = make_seg_tree(N + 1, max, 0);
	for(i = 0; i < N; i++){
		scanf("%d", &c);
		update(c, query(0, c, t) + 1, t);
	}
	printf("%d\n", N - query(0, N + 1, t));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:69:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:72:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &c);
   ^