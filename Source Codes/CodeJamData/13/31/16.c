#include <stdio.h>
#include <string.h>

int isconst(char c)
{
	return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') ? 1 : 0;
}

int main()
{
	int t;
	int i, j, n;
	int l, r;
	int stringlen;
	char string[1000001];
	unsigned long long ans;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%s %d", string, &n);
		stringlen = strlen(string);
		ans = 0;
		l = 0, r = -1;
		for(j = 0; j < stringlen; j++)
		{
			if(l < j) l = j;
			while(r - l + 1 < n)
			{
				r++;
				if(r == stringlen) break;
				if(isconst(string[r]) == 0) l = r + 1;
			}
			if(r == stringlen) break;
			ans += stringlen - r;
		}
		printf("Case #%d: %llu\n", i + 1, ans);
	}
	return 0;
}
