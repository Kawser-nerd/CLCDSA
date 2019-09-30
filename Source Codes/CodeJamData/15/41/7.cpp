/*
	Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int V = 110;
int _, n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char ch[] = {"v^<>"};
int has[V][V][4], R, C;
char mp[V][V];
int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d%d", &R, &C);
		for(int i = 0; i < R; ++i)
		scanf("%s", mp[i]);
		memset(has, 0, sizeof(has));
		for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
		for(int k = 0; k < 4; ++k)
		{
			for(int L = 1; ; ++L)
			{
				int tx = i + dx[k] * L;
				int ty = j + dy[k] * L;
				if(tx < 0 || tx >= R) break;
				if(ty < 0 || ty >= C) break;
				if(mp[tx][ty] != '.') has[i][j][k] = 1;
			}
		}
		int ret = 0;
		bool can = true;
		for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
		{
            if(mp[i][j] == '.') continue;
			int tmp = 2;
			for(int k = 0; k < 4; ++k)
			if(has[i][j][k])
			{
				tmp = min(tmp, 1);
				if(ch[k] == mp[i][j])
				{
					tmp = min(tmp, 0);
				}
			}
			if(tmp == 2) can = false;
			ret += tmp;
		}
		printf("Case #%d: ", ca);
		if(!can) puts("IMPOSSIBLE");
		else printf("%d\n", ret);
	}
	return 0;
}
