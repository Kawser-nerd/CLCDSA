/* ***********************************************
Author        :axp
Created Time  :2016/5/8 17:26:55
TASK		  :B.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;
const int N = 55;
int T;
int n;
ll m;
bool vis[N][N];
ll num[N];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d%lld",&n,&m);
		printf("Case #%d: ",kase);
		/*if(n<=2)
		{
			if(m>1)
				puts("IMPOSSIBLE");
			else
			{
				puts("POSSIBLE");
				puts("01");
				puts("00");
			}
			continue;
		}*/
		if( (1ll<<(n-2))<m)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		puts("POSSIBLE");
		memset(vis,0,sizeof vis);
		num[n]=1;
		for(int i=n-1;i>=2;i--)
		{
			num[i]=0;
			for(int j=i+1;j<=n;j++)
			{
				vis[i][j]=1;
				num[i]+=num[j];
			}
		}
		for(int i=2;i<=n;i++)
			if(m>=num[i])
			{
				vis[1][i]=1;
				m-=num[i];
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d",vis[i][j]);
			putchar(10);
		}
	}
    return 0;
}
