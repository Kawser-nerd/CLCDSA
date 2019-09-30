#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cycpair[2000000+1];

int main()
{
	for(int i = 1; i <= 2000000; i ++)
	{
		int vp = 1;
		int cnt = 0;
		while(vp * 10 <= i) 
		{
			vp *= 10;
			cnt ++;
		}
		
		int num = i;

		for(int j = 0; j < cnt; j ++)
		{
			num = num / 10 + num % 10 * vp;
			if(num > i)
			{
				cycpair[i].push_back(num);
			}
		}

		std::sort(cycpair[i].begin(), cycpair[i].end());
		cycpair[i].erase(std::unique(cycpair[i].begin(), cycpair[i].end()), cycpair[i].end());
	}

	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		int a,b;
		int ans = 0;
		scanf("%d%d",&a,&b);
		for(int i = a; i < b; i ++)
		{
			for(int j = 0; j < cycpair[i].size(); j ++)
			{
				if(cycpair[i][j] <= b)
				{
					ans ++;
				}
			}
		}
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}