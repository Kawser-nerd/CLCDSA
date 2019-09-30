#include <stdio.h>
#include <stdlib.h>
#define int long long
#define le9 (int)(1e9)

typedef struct {
	int N;
	int *u;
	int *u_rank;
	int *u_val;
}weighted_union_find;

//???N,???val?????union_find???
weighted_union_find *make_weighted_union_find(int N, int val){
	int i;
	weighted_union_find *wuf = (weighted_union_find *)malloc(sizeof(weighted_union_find));
	wuf->N = N;
	wuf->u = (int *)malloc(sizeof(int) * N);
	wuf->u_rank = (int *)malloc(sizeof(int) * N);
	wuf->u_val = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		wuf->u[i] = i;
		wuf->u_rank[i] = 1;
		wuf->u_val[i] = val;
	}
	return wuf;
}

//x??(??????)???
int root_wuf(int x, weighted_union_find *wuf){
	int *u = wuf->u;
	int *u_val = wuf->u_val;
	if(u[x] == x){
		return x;
	}
	else if(u[u[x]] == u[x]){
		return u[x];
	}
	else{
		int x_root = root_wuf(u[x], wuf);
		u_val[x] += u_val[u[x]];
		u[x] = x_root;
		return u[x];
	}
}

//x???????y???????????
void combine_wuf(int x, int y, weighted_union_find *wuf){
	int x_root = root_wuf(x, wuf);
	int y_root = root_wuf(y, wuf);
	int *u = wuf->u;
	int *u_rank = wuf->u_rank;
	int *u_val = wuf->u_val;
	if(x_root == y_root){
		return;
	}
	else if(u_rank[x_root] < u_rank[y_root]){
		u[x_root] = y_root;
		u_rank[y_root] += u_rank[x_root];
		u_rank[x_root] = 0;
		u_val[x_root] -= u_val[y_root];
	}
	else{
		u[y_root] = x_root;
		u_rank[x_root] += u_rank[y_root];
		u_rank[y_root] = 0;
		u_val[y_root] -= u_val[x_root];
	}
}

//x?y????????????1?,???????0???
int is_same_union_wuf(int x, int y, weighted_union_find *wuf){
	if(root_wuf(x, wuf) == root_wuf(y, wuf)){
		return 1;
	}
	else{
		return 0;
	}
}

//x?????????val???
void add_val_wuf(int x, int val, weighted_union_find *wuf){
	int x_root = root_wuf(x, wuf);
	wuf->u_val[x_root] += val;
}

//x?????????????
int rank_wuf(int x, weighted_union_find *wuf){
	return wuf->u_rank[root_wuf(x, wuf)];
}

//x?????
int val_wuf(int x, weighted_union_find *wuf){
	int x_root = root_wuf(x, wuf);
	int *u_val = wuf->u_val;
	if(x == x_root){
		return u_val[x];
	}
	else{
		return u_val[x_root] + u_val[x];
	}
}

signed main(){
	int N, Q, w, x, y, z, i;
	scanf("%lld%lld", &N, &Q);
	weighted_union_find *wuf = make_weighted_union_find(N, 1000000);
	for(i = 0; i < Q; i++){
		scanf("%lld%lld%lld%lld", &w, &x, &y, &z);
		x--;
		y--;
		if(w == 1){
			z %= 2;
			if(is_same_union_wuf(x, y, wuf) == 0){
				if(val_wuf(x, wuf) < 0 || val_wuf(y, wuf) < 0){
					combine_wuf(x, y, wuf);
					add_val_wuf(x, -le9, wuf);
				}
				else{
					if((val_wuf(x, wuf) + val_wuf(y, wuf)) % 2 != z){
						add_val_wuf(x, 1, wuf);
					}
					combine_wuf(x, y, wuf);
				}
			}
			else{
				if((val_wuf(x, wuf) + val_wuf(y, wuf)) % 2 != z){
					add_val_wuf(x, -le9, wuf);
				}
			}
		}
		else{
			if(is_same_union_wuf(x, y, wuf) == 1 && (val_wuf(x, wuf) < 0 || (val_wuf(x, wuf) + val_wuf(y, wuf)) % 2 == 0)){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:106:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &Q);
  ^
./Main.c:109:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld", &w, &x, &y, &z);
   ^