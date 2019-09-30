#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int S;
string name[100];
int Q;
string query[1000];
int dp[100][1001];
int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}
void gotoendofline()
{
	while(getchar()!='\n');
}
int main()
{
	int i;
	int T;
	scanf("%d", &T);
	gotoendofline();
	for(int t = 0; t<T; t++)
	{
		int S;
		scanf("%d", &S);
		gotoendofline();
		for(i = 0; i<S; i++)
			getline(cin, name[i]);
		scanf("%d", &Q);
		gotoendofline();
		for(i = 0; i<Q; i++)
			getline(cin, query[i]);
		memset(dp, 0, sizeof(dp));
		for(i = 0; i<S; i++)
			if(query[0]==name[i])
				dp[i][1] = 1000000;
		for(int q = 2; q<=Q; q++)
		{
			for(int s = 0; s<S; s++)
			{
				dp[s][q] = 1000000;
				if(query[q-1]==name[s])
					continue;
				for(int prevs = 0; prevs<S; prevs++)
				{	
					dp[s][q] = min(dp[s][q], dp[prevs][q-1] + (prevs==s ? 0 : 1));
				}
			}
		}
		int res = 1000000;
		for(i = 0; i<S; i++)
			if(dp[i][Q]<res)
				res =dp[i][Q];
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}
