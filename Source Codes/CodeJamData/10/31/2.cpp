#include <iostream>

using namespace std;

const int MAX = 1005;

struct Line
{
	int start;
	int end;
}line[MAX];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("aout.txt","w",stdout);
	int T, cases;
	scanf("%d",&T);
	cases = 0;
	while (T--)
	{
		int i,j,num, ans;
		scanf("%d",&num);
		for(i = 0; i < num; ++i)
			scanf("%d %d", &line[i].start, &line[i].end);
		ans = 0;
		for(i = 0; i < num-1; ++i)
		{
			for (j = i+1; j < num; ++j)
			{
				if((line[i].start<line[j].start && line[i].end > line[j].end) ||(line[i].start>line[j].start && line[i].end < line[j].end) )
					ans++;
			}
		}
		printf("Case #%d: %d\n",++cases,ans);
	}
	return 0;
}