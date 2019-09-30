#include <stdio.h>
#include <stdlib.h>

int p, k, l;
int x[1001];
long long ans;

int cmp(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int go(){
	int i;
	ans = 0;
	scanf("%d%d%d", &p, &k, &l);
	if(p * k < l)
		return 0;
	for(i = 0; i < l; i++){
		scanf("%d", &x[i]);
	}
	qsort(x, l, sizeof(int), cmp);
	for(i = 0; i < l; i++){
		ans += (i / k + 1) * x[i];
	}
	return 1;
}

int main(){
	int cs, c;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &cs);
	for(c = 1; c <= cs; c++){
		if(go()){
			printf("Case #%d: %I64d\n", c, ans);
		}
		else{
			printf("Case #%d: Impossible\n", c);
		}
	}
	return 0;
}
