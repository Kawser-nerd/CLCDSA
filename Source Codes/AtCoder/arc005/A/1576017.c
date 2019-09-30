#include<stdio.h>
#include<string.h>

const char *s1 = "TAKAHASHIKUN";
const char *s2 = "Takahashikun";
const char *s3 = "takahashikun";

int main()
{
	int n, i, cnt = 0;

	scanf("%d", &n);
	getchar();

	for(i = 0; i < n; i++)
	{
		char ch;
		char temp[101];
		int j = 0;

		while((ch = getchar()) != ' ' && ch != '.')
			temp[j++] = ch;
		temp[j] = '\0';

		if(strcmp(temp, s1) == 0 || strcmp(temp, s2) == 0 || strcmp(temp, s3) == 0)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^