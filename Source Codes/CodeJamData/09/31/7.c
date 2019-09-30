#include <stdio.h>
#include <string.h>

char s[61];
int len;
int trans['z' + 1];
int used;

void read()
{
	scanf("%s\n", s);
	len = strlen(s);
}

void solve()
{
	long long r = 0;
	int i, zero;
	char ch;
	for(ch = 'a'; ch <= 'z'; ch++)trans[ch] = -1;
	for(ch = '0'; ch <= '9'; ch++)trans[ch] = -1;
//	if(len == 1)trans[s[0]] = 0, used = 0, zero = 0;
//	else trans[s[0]] = 1, used = 1, zero = 1;
	trans[s[0]] = 1, used = 1, zero = 1;
	for(i = 0; i < len; i++)
	{
		if(trans[s[i]] == -1)
		{
			if(zero)trans[s[i]] = 0, zero = 0;
			else trans[s[i]] = ++used;
		}
		s[i] = trans[s[i]];
	}
	used++;
	for(i = 0; i < len; i++)
		r = r * used + s[i];
	printf(" %lld\n", r);
}

int main()
{
	int n, test;
//	freopen("A.in", "r", stdin);
	scanf("%d\n", &n);
	for(test = 1; test <= n; test++)
	{
		printf("Case #%d:", test);
		read();
		solve();
	}
	return 0;
} 
