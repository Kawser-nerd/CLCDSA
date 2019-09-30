#include <stdio.h>
#include <stdlib.h>

#define datatype int
#define inf (int)(1e9 + 7)

typedef struct {
	datatype *dat;
	int n; //???
	int N; //?????????2????
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
	t->n = n;
	t->N = N;
	t->f = f;
	t->e = e;
	return t;
}

//i?????x?????
void update(int i, datatype val, seg_tree *t){
	if(i < 0 || t->n <= i){
		printf("In function 'update':\nrefered out of array\n");
	}
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
	if(a < 0 || b < 0 || t->n <= a || t->n <= b){
		printf("In function 'query':\nrefered out of array\n");
	}
	if(a >= b){
		return t->e;
	}
	else{
		return query_sub(a, b, 0, 0, t->N, t);
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

int main(){
	int N, C, A, i, grundy = 0, l, h, r;
	scanf("%d", &N);
	seg_tree *t = make_seg_tree(N, min, inf);
	update(0, 0, t);
	for(i = 1; i < N; i++){
		update(i, -inf, t);
	}
	for(i = 1; i < N; i++){
		scanf("%d%d", &C, &A);
		l = -1;
		r = N;
		while(r - l > 1){
			h = (l + r) / 2;
			if(query(0, h, t) < i - C){
				r = h;
			}
			else{
				l = h;
			}
		}
		update(l, i, t);
//		printf("i = %d, grundy = %d\n", i, l);
		if(A % 2 == 1){
			grundy ^= l;
		}
	}
	if(grundy == 0){
		printf("Second\n");
	}
	else{
		printf("First\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:83:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:90:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &C, &A);
   ^