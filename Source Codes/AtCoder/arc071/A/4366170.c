#include<stdio.h>

int Min(int a, int b) { if (a < b) { return a; }return b; }

int fa[52][26];//?????????????
int fb[26];//???????????
int main() {
	int N;
	char S[52];
	int yes = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)//???
	{
		scanf("%s", S);
		for (int j = 0; j < strlen(S); j++)//???????
		{
			fa[i][S[j] - 'a']++;
			fb[S[j] - 'a']++;
		}
	}

	for (int j = 0; j < 26; j++)//???????
	{
		int cnt = 0;
		int cntmin = 60;//????????????????????????
		for (int i = 0; i < N; i++)//???
		{
			if (fa[i][j] >= 1)//??????????????
			{
				cnt++;
				cntmin = Min(cntmin, fa[i][j]);//????????????????????????
			}
			else //???????????????
			{
				break;//????????
			}
		}
		if (cnt == N)//??????????????????
		{
			while (cntmin > 0) 
			{
				printf("%c", 'a' + j);
				cntmin--;
				yes++;
			}
		}
	}
	if (yes==0)
	{
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:23: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   for (int j = 0; j < strlen(S); j++)//???????
                       ^
./Main.c:15:23: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:15:23: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^