//<??>
//????????????????????
//????????????????
//??????????
//??????????????? ?/=10 ????

#include<stdio.h>
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	int *D = (int *)malloc(sizeof(int)*K);
	int num[10] = { 0 };
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &D[i]);
		num[D[i]] = 1;
	}
	for (int ans = N; ; ans++)
	{
		int NN = ans;
		while (1) {
			if (num[NN % 10] == 1) {
				break;
			}
			NN /= 10;
			if (NN == 0)
			{
				printf("%d\n", ans);
				return 0;
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:18: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  int *D = (int *)malloc(sizeof(int)*K);
                  ^
./Main.c:11:18: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:11:18: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &D[i]);
   ^