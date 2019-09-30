#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>;
using namespace std;

int T;
long long N;
int pd, pg;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> T;
	for (int i=1; i<=T; i++)
	{
		cin >> N >> pd >> pg;
		if (pg == 0 && pd > 0)
			printf("Case #%d: Broken\n", i);
		else if (pg == 100 && pd < 100)
			printf("Case #%d: Broken\n", i);
		else if (pd==0)
			printf("Case #%d: Possible\n", i);
		else
		{
			int index2 = 0, index5 = 0;
			while (pd % 2==0)
			{
				index2++;
				pd /=2;
			}
			while (pd% 5 == 0)
			{
				index5++;
				pd/=5;
			}
			int ret = 1;
			for (int i=index2; i<2; i++) ret *=2;
			for (int i=index5; i<2; i++) ret *=5;
			if (ret <= N)
				printf("Case #%d: Possible\n", i);
			else
				printf("Case #%d: Broken\n", i);
		}
	}
}