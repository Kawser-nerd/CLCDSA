#include<stdio.h>
int main(void) {
	int N, T;
	int c[1000];
	int t[1000];
	int k;
	int c0 = 1000000;
	int answer;
	scanf("%d%d", &N, &T);

	for (k = 1; k <= N; k++) {
		scanf("%d%d", &c[k], &t[k]);
		if (t[k] <= T) {
			if (c[k] < c0) {
				c0 = c[k];
				answer = c0;
			}
		}
     
	}
  if(answer == 0){
    printf("TLE");
  }
  else{
	printf("%d", answer);
  }
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &T);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &c[k], &t[k]);
   ^