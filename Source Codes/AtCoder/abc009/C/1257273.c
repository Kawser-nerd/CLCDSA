#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, K, i, j, k;
	scanf("%d %d", &N, &K);
	int L = N - K;
	char *s = (char *)malloc(sizeof(char) * (N + 1));
	char *t = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", s);
	int *snum = (int *)malloc(sizeof(int) * 26);
	int *tnum = (int *)malloc(sizeof(int) * 26);
	int sum;
	for(i = 0; i < 26; i++){
		snum[i] = 0;
		tnum[i] = 0;
	}
	for(i = 0; i < N; i++){
		snum[(int)s[i] - (int)'a']++;
		tnum[(int)s[i] - (int)'a']++;
	}
	for(i = 0; i < N; i++){
		snum[(int)s[i] - (int)'a']--;
		for(j = 0; j < 26; j++){
			if(tnum[j] != 0){
				t[i] = (char)(j + (int)'a');
				tnum[j]--;
				sum = 0;
				for(k = 0; k < 26; k++){
					sum += min(snum[k], tnum[k]);
				}
				if(s[i] == t[i]){
					L--;
				}
				if(sum >= L){
					break;
				}
				if(s[i] == t[i]){
					L++;
				}
				tnum[j]++;
			}
		}
	}
	t[N] = '\0';
	printf("%s\n", t);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &K);
  ^
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^