#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1500;

bool p[maxn][maxn];
int X1[maxn],X2[maxn],Y1[maxn],Y2[maxn];
int n;

int father[maxn];

int ff(int x)
{
	if(father[x]==x) return x;
	else return father[x] = ff(father[x]);
}

bool IN(int x,int y,int a)
{
	return (X1[a]<=x && x<=X2[a] && Y1[a]<=y && y<=Y2[a]);
}

bool contact(int a,int b)
{
	if(X1[a]<=X1[b] && X1[b]<=X2[a] && Y1[b]<=Y1[a] && Y1[a]<=Y2[b]) return true;
	swap(a,b);
	if(X1[a]<=X1[b] && X1[b]<=X2[a] && Y1[b]<=Y1[a] && Y1[a]<=Y2[b]) return true;
	if(IN(X1[a],Y1[a],b) || IN(X1[a],Y2[a],b) || IN(X2[a],Y1[a],b) || IN(X2[a],Y2[a],b)) return true;
	swap(a,b);
	if(IN(X1[a],Y1[a],b) || IN(X1[a],Y2[a],b) || IN(X2[a],Y1[a],b) || IN(X2[a],Y2[a],b)) return true;
	return false;
}

int main()
{
	int ntest;
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
			father[i] = i;
		}
		for(int i=0;i<n;i++)
		{
			X1[n] = X1[i] - 1;
			X2[n] = X2[i];
			Y1[n] = Y1[i];
			Y2[n] = Y2[i] + 1;
			X1[n+1] = X1[i];
			X2[n+1] = X2[i] + 1;
			Y1[n+1] = Y1[i] - 1;
			Y2[n+1] = Y2[i];
			for(int j=i+1;j<n;j++)
			{
				if(contact(n,j) || contact(n+1,j))
					father[ff(i)] = ff(j);
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			int MIN = X1[i] + Y1[i];
			int MAX1 = X2[i];
			int MAX2 = Y2[i];
			for(int j=i+1;j<n;j++)
				if(ff(i)==ff(j))
				{
					MIN = min(MIN,X1[j]+Y1[j]);
					MAX1 = max(MAX1,X2[j]);
					MAX2 = max(MAX2,Y2[j]);
				}
			ans = max(ans,MAX1+MAX2-MIN+1);
		}
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
