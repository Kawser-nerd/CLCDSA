#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int compar(const int *val1, const int *val2) {
	if (*val1 < *val2)  return -1;
	else if(*val1 == * val2)  return 0;
	else return 1;
}

/*
void showScoreList(int s[],int n){
	printf("s = [ ");
	for (int i = 0; i < n; ++i)	printf("%d ", s[i]);
	printf("]\n");
}
*/

int main(int argc, char const *argv[])
{	
	int N,s[100];
	int max = 0,min = 0x7F,pat,sum = 0;
	scanf("%d",&N);

	// Input
	for (int i = 0; i < N; ++i){
		scanf(" %d",&s[i]);
		sum += s[i];
	}

	// Output
	if(sum % 10 != 0){
		printf("%d\n",sum);
		return 0;
	}
	else{
		// showScoreList(s,N);
		qsort(s,N, sizeof(int), (int (*)(const void *, const void *))compar);
		// showScoreList(s,N);
		for (int i = 0; i < N; ++i)
		{
			if(s[i] % 10 != 0){
				sum -= s[i];
				break;
			}
		}
		sum = (sum % 10 == 0) ? 0 : sum;
		printf("%d\n", sum);
	}
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&s[i]);
   ^