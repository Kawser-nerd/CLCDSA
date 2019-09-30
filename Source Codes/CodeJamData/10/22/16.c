#include<stdio.h>
int main(void){
	int C, I;
	scanf("%d", &C);
	for(I = 1; I <= C; ++I){
		int n, k, b, t, i, OK_num = 0, front_OK;
		int x[100], v[100];
		int OK[100] = {0};
		int ans = 0;
		scanf("%d%d%d%d", &n, &k, &b, &t);
		for(i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		for(i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		for(i = n-1; OK_num != k && i >= 0; --i){
			if(x[i]+t*v[i] >=b){
				OK[i] = 1;
				++OK_num;
			}
		}
		if(OK_num != k){
			printf("Case #%d: IMPOSSIBLE\n", I);
			continue;
		}
		front_OK = OK_num;
		for(i = n-1; front_OK != 0;--i){
			if(OK[i] == 0)
				ans += front_OK;
			else
				--front_OK;	
		}
		printf("Case #%d: %d\n", I, ans);
	}
	return 0;
}
