#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<stack>

using namespace std;

const int maxn = 205;

char s[maxn], t[maxn];
int len;
int cnt;

bool check(char t[])
{
	long long p = 0;
	for(int i=0; t[i]; i++)
	{
		p = p * 2 + (t[i] - '0');
	}

	long long lower = 0, upper = 0x7fffffffll;

	while(lower + 1 < upper)
	{
		long long mid = (lower + upper) / 2;
		if(mid * mid <= p)
			lower = mid;
		else 
			upper = mid;
	}

	if(lower * lower == p) return true;
	else return false;
}

int main()
{
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test=1; test<=ntest; test++)
	{
		fprintf(stderr, "%d\n", test);

		scanf("%s", &s);
		len = strlen(s);

		cnt = 0;

		for(int i=0; i<len; i++)
			if(s[i] == '?')
				cnt++;

		for(int mask = 0; mask < (1<<cnt); mask++)
		{
			int M = mask;
			for(int i=0; i<=len; i++) t[i] = s[i];
			int p = mask;
			for(int i=0; i<len; i++)
				if(t[i] == '?')
				{
					t[i] = ('0' + M % 2);
					M /= 2;
				}

			if(check(t))
			{
				printf("Case #%d: %s\n", test, t);
				break;
			}
		}

	}
	return 0;
}
