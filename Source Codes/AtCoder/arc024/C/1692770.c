#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define datatype int *

//????
int compare(datatype a, datatype b){
	int i;
	for(i = 0; i < 26; i++){
		if(a[i] != b[i]){
			return a[i] - b[i];
		}
	}
	return 0;
}

//??
void sort_sub(datatype *origin, int left, int right, datatype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare(tmp[j], tmp[k]) <= 0 && j < half){
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

void sort(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
}

int main(){
	int N, K, i, j;
	scanf("%d%d", &N, &K);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	int **alf_num = (int **)malloc(sizeof(int *) * (N - K + 1));
	for(i = 0; i <= N - K; i++){
		alf_num[i] = (int *)malloc(sizeof(int) * 27);
		for(j = 0; j < 26; j++){
			alf_num[i][j] = 0;
		}
		alf_num[i][26] = i;
	}
	for(i = 0; i < K; i++){
		alf_num[0][(int)S[i] - (int)'a']++;
	}
	for(i = 1; i <= N - K; i++){
		for(j = 0; j < 26; j++){
			alf_num[i][j] = alf_num[i - 1][j];
		}
		alf_num[i][(int)S[i - 1] - (int)'a']--;
		alf_num[i][(int)S[i + K - 1] - (int)'a']++;
	}
	sort(alf_num, N - K + 1);
	for(i = 0; i <= N - K; i = i){
		for(j = i + 1; j <= N - K; j++){
			if(compare(alf_num[i], alf_num[j]) != 0){
				break;
			}
		}
		if(alf_num[j - 1][26] - alf_num[i][26] >= K){
			printf("YES\n");
			return 0;
		}
		i = j;
	}
	printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:51:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^