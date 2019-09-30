#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int Min(int a, int b) { if (a < b) { return a; }return b; }
int ups(const void*a, const void*b) { return strcmp((char*)a, (char*)b); }
char S[5002];
char a[25002][6];
int main() {
	int K;
	scanf("%s%d", S, &K);
	int n = strlen(S);
	int i = 0;//S[]??????????
	int j;//?????
	int cnt = 0;//????????????????S[]??????????????
	int num = 0;//????????????

	for (i = 0; i < n; i++)//S[]??????????
	{
		for (j = 0; j < 5; j++)//??????
		{
			for (cnt = 0; cnt < j + 1; cnt++)//????????????????
			{
				a[num][cnt] = S[i + cnt];
				//printf("a[%d][%d]=%c\n",num,cnt, a[num][cnt]);
			}
			//puts("");
			//puts(a[num]);
			//puts("");
			num++;
		}
	}

	//for (int i = 0; i < num; i++)
	//{
	//	printf("a[%d]:%s\n", i, a[i]);
	//}
	qsort(a, num, 6, ups);
	//for (int i = 0; i < num; i++)
	//{
	//	printf("q a[%d]:%s\n", i, a[i]);
	//}

	if (K==1)
	{
		puts(a[0]);
		return 0;
	}else
	{
		int nmb = 1;
		for (int i = 1; i < num; i++)
		{
			if (strcmp(a[i], a[i - 1]) != 0) 
			{
				nmb++;
			}
			if (nmb == K) 
			{
				puts(a[i]);
				return 0;
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d", S, &K);
  ^