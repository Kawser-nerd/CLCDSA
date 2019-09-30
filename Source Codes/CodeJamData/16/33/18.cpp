/* ***********************************************
Author        :axp
Created Time  :2016/5/8 18:16:30
TASK		  :C.cpp
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

int T;
int a,b,c,k;
int ans;

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&k);
		ans=a*b*min(c,k);
		printf("Case #%d: %d\n",kase,ans);
		int now;
		int be=1;
		for(int i=1;i<=a;i++)
		{
			now=be++;
			for(int j=1;j<=b;j++)
				for(int m=1;m<=min(c,k);m++)
				{
					printf("%d %d %d\n",i,j,now);
					now++;
					if(now>c)now-=c;
				}
		}
	}
    return 0;
}
