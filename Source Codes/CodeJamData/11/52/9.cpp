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

const int maxn = 50000 + 50;
const int range = 50000 + 50;
const int inf = 2147483647;

int n;
int a[maxn];
int b[range];

int T[maxn], cnt;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test=1; test<=ntest; test++)
	{
		memset(b, 0, sizeof(b));

		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
			a[i]++;
			b[a[i]]++;
		}

		printf("Case #%d: ", test);
		
		int cnt = 0;
		int ans = inf;
		for(int i=1; i<=10010; i++)
		{
			sort(T, T+cnt);
			while(cnt > b[i])
			{
				cnt--;
				if(ans > T[cnt]) ans = T[cnt];
			}

			while(cnt < b[i])
			{
				T[cnt++] = 0;
			}

			for(int i=0; i<cnt; i++) T[i]++;
		}

		printf("%d\n", ans == inf ?  0 : ans);
	}
	return 0;
}