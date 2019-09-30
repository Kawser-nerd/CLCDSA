#include <stdio.h>
#include <stdlib.h>

#define datatype int

typedef struct {
	int w;
	int h;
}pair;

typedef struct {
	datatype *dat;
	int N; //2????
	datatype (*f)(datatype x, datatype y);//??
	datatype e;//??????
}seg_tree;

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

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

//????
int compare(pair a, pair b){
	if(a.w < b.w){
		return -1;
	}
	else if(a.w > b.w){
		return 1;
	}
	else if(a.h > b.h){
		return -1;
	}
	else if(a.h < b.h){
		return 1;
	}
	else{
		return 0;
	}
}

//??
void sort_sub(pair *origin, int left, int right, pair *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k]) <= 0 && j < half) || k == right){
				origin[i] = tmp[j];
				j++;
			}
			else{
				origin[i] = tmp[k];
				k++;
			}
		}
	}
}

void sort(pair *origin, int N){
	pair *tmp = (pair *)malloc(sizeof(pair) * N);
	sort_sub(origin, 0, N, tmp);
}

int main(){
	int N, i, hmax = 0;
	scanf("%d", &N);
	pair *p = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &(p[i].w), &(p[i].h));
		hmax = max(hmax, p[i].h);
	}
	sort(p, N);
	seg_tree *t = make_seg_tree((hmax + 1), &max, 0);
	for(i = 0; i < N; i++){
		update(p[i].h, query(0, p[i].h, t) + 1, t);
	}
	printf("%d\n", query(0, hmax + 1, t));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:120:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:123:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &(p[i].w), &(p[i].h));
   ^