#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define FR(i,a,n) for(int (i) = (a); (i) < (n); (i)++)
#define FOR(i,n) FR(i,0,n)
#define RF(i,a,n) for(int (i) = int(n)-1; (i) >= (a); (i)--)
#define ROF(i,n) RF(i,0,n)
int R, C;
int DP[16][1<<16];
char m[4][5];

int dr[8] = {-1,1,0,0,-1,-1,1,1};
int dc[8] = {0,0,-1,1,-1,1,-1,1};

int go(int p, int st)
{
	int& res = DP[p][st];
	if(res!=-1)
		return res;
	res = 1;
	int r = p/4;
	int c = p%4;
	FOR(d,8)
	{
		int nr = r+dr[d];
		int nc = c+dc[d];
		if(nr<0 || nr>=R || nc<0 || nc>=C)
			continue;
		if(st&(1<<(nr*4+nc)))
			continue;
		int ret = go(nr*4+nc, st|(1<<(nr*4+nc)));
		if(ret==1)
		{
			return res = 0;
		}
	}
	return res = 1;
}
int main()
{
	int TESTS;
	scanf("%d", &TESTS);
	FOR(tests,TESTS)
	{
		scanf("%d%d", &R, &C);
		memset(DP, -1, sizeof(DP));
		FOR(r,R)
			scanf("%s", m[r]);
		int start = 0;
		int state = 0;
		FOR(r,R) FOR(c,C)
		{
			if(m[r][c]=='K')
			{
				start = r*4+c;
			}
			else if(m[r][c]=='#')
			{
				state|=1<<(r*4+c);
			}
		}
		state|=1<<start;
		if(go(start,state))
			printf("Case #%d: B\n", tests+1);
		else
			printf("Case #%d: A\n", tests+1);
	}
	return 0;
}
