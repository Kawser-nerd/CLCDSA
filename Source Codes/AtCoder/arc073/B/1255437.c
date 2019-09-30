#include <stdio.h>
#include <stdlib.h>

#define datatype long long int

datatype max(datatype a, datatype b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

datatype min(datatype a, datatype b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int compare(datatype a, datatype b){
	if(a < b){
		return 1;
	}
	else if(a > b){
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
			if((compare(sub1[j], sub2[k]) == -1 && j != N1) || (k == N2)){
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
	datatype *ans;
	if(N == 0){
		ans = NULL;
	}
	else{
		ans = sort_sub(origin, N);
	}
	free(origin);
	return ans;
}

int main(){
	int N, W, i, j, k, w1, wi;
	scanf("%d%d", &N, &W);
	datatype **v = (datatype **)malloc(sizeof(datatype *) * 4);
	int *vnum = (int *)malloc(sizeof(int) * 4);
	for(i = 0; i < 4; i++){
		v[i] = (datatype *)malloc(sizeof(datatype) * N);
		vnum[i] = 0;
	}
	scanf("%d%lld", &w1, &v[0][0]);
	vnum[0]++;
	for(i = 1; i < N; i++){
		scanf("%d", &wi);
		scanf("%lld", &v[wi - w1][vnum[wi - w1]]);
		vnum[wi - w1]++;
	}
	datatype **vsum = (datatype **)malloc(sizeof(datatype *) * 4);
	for(i = 0; i < 4; i++){
		v[i] = sort(v[i], vnum[i]);
		vsum[i] = (datatype *)malloc(sizeof(datatype) * (vnum[i] + 1));
		vsum[i][0] = 0;
		for(j = 0; j < vnum[i]; j++){
			vsum[i][j + 1] = vsum[i][j] + v[i][j];
		}
	}
	datatype ans = 0;
	for(i = 0; i <= vnum[3] && W - (w1 + 3) * i >= 0; i++){
		for(j = 0; j <= vnum[2] && W - (w1 + 3) * i - (w1 + 2) * j >= 0; j++){
			for(k = 0; k <= vnum[1] && W - (w1 + 3) * i - (w1 + 2) * j - (w1 + 1) * k >= 0; k++){
				ans = max(vsum[3][i] + vsum[2][j] + vsum[1][k] + vsum[0][min(vnum[0], (W - (w1 + 3) * i - (w1 + 2) * j - (w1 + 1) * k) / w1)], ans);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:77:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &W);
  ^
./Main.c:84:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld", &w1, &v[0][0]);
  ^
./Main.c:87:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &wi);
   ^
./Main.c:88:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &v[wi - w1][vnum[wi - w1]]);
   ^