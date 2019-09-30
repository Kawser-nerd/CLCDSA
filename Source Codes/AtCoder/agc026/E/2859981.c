#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *s;
	int i;
}pair;

int compare_string(const void *a, const void *b){
	return strcmp(*(char **)b, *(char **)a);
}

int compair(const void *a, const void *b){
	pair pa = *(pair *)a, pb = *(pair *)b;
	int res = strcmp(pb.s, pa.s);
	if(res == 0){
		return pa.i - pb.i;
	}
	else{
		return res;
	}
}

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, i, j, k, l;
	scanf("%d", &N);
	char *S = (char *)malloc(sizeof(char) * (2 * N + 1));
	scanf("%s", S);
	int *T = (int *)malloc(sizeof(int) * (2 * N + 1));
	int *a = (int *)malloc(sizeof(int) * (N + 1));
	int *b = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 0, j = 0, k = 0; i < 2 * N; i++){
		if(S[i] == 'a'){
			T[i] = j;
			a[j] = i;
			j++;
		}
		else{
			T[i] = k;
			b[k] = i;
			k++;
		}
	}
	a[N] = 2 * N;
	b[N] = 2 * N;
	int *left = (int *)malloc(sizeof(int) * N);
	int *right = (int *)malloc(sizeof(int) * N);
	left[0] = 0;
	for(i = 1, j = 1; i < N; i++){
		if(a[i] > b[i - 1] && b[i] > a[i - 1]){
			left[j] = i;
			right[j - 1] = i;
			j++;
		}
	}
	right[j - 1] = N;
	int K = j, prevj;
//	printf("K = %d\n", K);
	pair *p = (pair *)malloc(sizeof(pair) * K);
	for(i = 0; i < K; i++){
		l = max(a[right[i] - 1] - b[left[i]], b[right[i] - 1] - a[left[i]]) + 1;
		p[i].s = (char *)malloc(sizeof(char) * (l + 1));
		p[i].i = i;
		if(a[left[i]] < b[left[i]]){
			for(j = left[i], k = 0; j < right[i]; ){
				p[i].s[k] = 'a';
				p[i].s[k + 1] = 'b';
				k += 2;
				prevj = j;
				while(a[j] < b[prevj] && j < right[i]){
					j++;
				}
			}
			p[i].s[k] = '\0';
		}
		else{
			int d = right[i] - left[i];
			char **sub = (char **)malloc(sizeof(char *) * d);
			for(j = left[i]; j < right[i]; j++){
				sub[j - left[i]] = (char *)malloc(sizeof(char) * (2 * (right[i] - j) + 1));
				for(k = b[left[i]], l = 0; k <= a[right[i] - 1]; k++){
					if(T[k] >= j){
						sub[j - left[i]][l] = S[k];
						l++;
					}
				}
				sub[j - left[i]][l] = '\0';
//				printf("sub[%d] = %s\n", j - left[i], sub[j - left[i]]);
			}
//			printf("qsort!\n");
			qsort(sub, d, sizeof(char *), compare_string);
/*			for(j = 0; j < d; j++){
				printf("sub[%d] = %s\n", j, sub[j]);
			}
*/			for(j = 0; sub[0][j] != '\0'; j++){
				p[i].s[j] = sub[0][j];
			}
			p[i].s[j] = '\0';
		}
	}
	int ab = 0;
	for(i = K - 1; i >= 0; i--){
		if(p[i].s[0] == 'a'){
			for(j = 0; p[i].s[j] != '\0'; j++){}
			ab += j / 2;
		}
		else{
			break;
		}
	}
	qsort(p, K, sizeof(pair), compair);
/*	for(i = 0; i < K; i++){
		printf("i = %d\n", i);
		printf("(i, s) = (%d, %s))\n", p[i].i, p[i].s);
	}
*/	for(i = 0, j = -1; i < K; i++){
//		printf("\n(i, j) = (%d, %d)\n", i, j);
		if(p[i].i > j && p[i].s[0] == 'b'){
			for(k = 0; p[i].s[k] != '\0'; k++){
				printf("%c", p[i].s[k]);
			}
			j = p[i].i;
		}
	}
	for(i = 0; i < ab; i++){
		printf("ab");
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^