#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void change(char **s, char **t)
{
	char *p;

	p = *s;
	*s = *t;
	*t = p;
}

int check(char *s, char *t)
{
	int i;

	for(i = 0; i < strlen(s) && i < strlen(t); i++)
		if(s[strlen(s) - 1 - i] > t[strlen(t) - 1 - i])
			return 1;
		else if(s[strlen(s) - 1 - i] < t[strlen(t) - 1 - i])
			return 0;

	if(strlen(s) > strlen(t))
		return 1;
	else
		return 0;
}

int main()
{
	int n, i, j;
	char **p;

	scanf("%d", &n);

	p = (char **)calloc(n, sizeof(char *));

	for(i = 0; i < n; i++)
	{
		char temp[21];

		while(getchar() != '\n')
			;

		scanf("%s", temp);

		p[i] = malloc(strlen(temp) + 1);
		strcpy(p[i], temp);
	
	}


	for(i = 0; i < n - 1; i++)
		for(j = n - 1; j > i; j--)
			if(check(p[j - 1], p[j]))
				change(&p[j - 1], &p[j]);


	for(i = 0; i < n; i++)
		printf("%s\n", p[i]);


	for(i = 0; i< n; i++)
		free(p[i]);
	free(p);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", temp);
   ^