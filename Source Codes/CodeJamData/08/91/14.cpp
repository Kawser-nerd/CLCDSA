#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<set>
#include<vector>
#include<list>
#include<queue>

using namespace std;

const int inf = 2147483647;
const double eps = 1e-7;

template<class T> T abs(T x) {return x>0?x:-x;}
template<class T> string toString(T x) {string ret; stringstream sin; sin<<x; sin>>ret; return ret;}

const int maxn = 10000 + 50;

int n,ntest;
int x[maxn],y[maxn],z[maxn];
int IN[maxn],OUT[maxn];

int main()
{
	freopen("A2.in","r",stdin);
	freopen("A2.out","w",stdout);
	scanf("%d",&ntest);
	for(int test = 1; test <= ntest; test++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
		int ans = 0;
		for(int X=0;X<=10000;X++)
		{
			int p=10000-X;
			memset(IN,0,sizeof(IN));
			memset(OUT,0,sizeof(OUT));
			for(int i=0;i<n;i++)
			{
				if(x[i]<=X && y[i]<=p-z[i])
				{
					IN[y[i]]++;
					OUT[p-z[i]]++;
				}
			}
			int tmp = 0;
			for(int i=0;i<=10000;i++)
			{
				tmp += IN[i];
				if(ans < tmp) ans = tmp;
				tmp -= OUT[i];
			}
		}
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
