#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1024];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		for(int sz = n; sz > 0; sz--)
		{
			int mval = a[0], mpos = 0;
			for(int i = 1; i < sz; i++)
				if(mval > a[i])
					mval = a[i], mpos = i;
			ans += min(mpos, sz - 1 - mpos);
			for(int i = mpos; i < sz - 1; i++)
				a[i] = a[i + 1];
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
