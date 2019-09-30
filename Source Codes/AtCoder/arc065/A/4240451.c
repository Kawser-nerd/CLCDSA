#include<stdio.h>
#include<string.h>

int main() {
	char S[100002];
	scanf("%s", S);
	long long len = strlen(S);
	for (long long i = len - 1; i > 0;)
	{
		if (i >= 4 && !strcmp(S + i - 4, "dream")) 
		{
			i -= 5; 
			S[i + 1] = 0;
		}
		else if (i >= 6 && !strcmp(S + i - 6, "dreamer")) 
		{ 
			i -= 7; 
			S[i + 1] = 0;
		}
		else if (i >= 4 && !strcmp(S + i - 4, "erase")) 
		{ 
			i -= 5; 
			S[i + 1] = 0;
		}
		else if (i >= 5 && !strcmp(S + i - 5, "eraser")) 
		{
			i -= 6; 
			S[i + 1] = 0;
		}
		//printf("%d\n", i);
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^