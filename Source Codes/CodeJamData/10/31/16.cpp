// I
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
const int MAX=2100;

int N;
struct NODE
{
	int a,b;
}nod[MAX];

bool cmp(NODE x,NODE y)
{
	return x.a<y.a;
}
int main()
{
	freopen("F:\\A-large.in","r",stdin);
	freopen("F:\\A-large.out","w",stdout);
	
	//freopen("F:\\A-small-attempt0.in","r",stdin);
	//freopen("F:\\A-small-attempt0.out","w",stdout);
	int i,j,T;scanf("%d",&T);
	int CN=0;
	while(T--)
	{
		scanf("%d",&N);
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&nod[i].a,&nod[i].b);
		}
		sort(&nod[1],&nod[N+1],cmp);
		int res=0;
		for(i=1;i<=N;i++)
		{
			for(j=i+1;j<=N;j++)
			{
				if(nod[i].b>nod[j].b) res++;
			}
		}
		printf("Case #%d: %d\n",++CN,res);
		
	}
	//system("pause");
	return 0;
}
