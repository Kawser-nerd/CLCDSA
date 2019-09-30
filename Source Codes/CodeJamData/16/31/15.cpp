#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int sum[26];
int n_sum[26];
int n;
char pk[2];
int ss;
bool pick_two()
{
	if(ss<2)return false;
	for(int i=0;i<n;i++)n_sum[i]=sum[i];
	int maxn=-1,k=-1;
	for(int i=0;i<n;i++)
	{
		if(maxn<n_sum[i])
		{
			maxn=n_sum[i];
			k=i;
		}
	}
	n_sum[k]--;
	pk[0]=k+'A';
	maxn=-1,k=-1;
	for(int i=0;i<n;i++)
	{
		if(maxn<n_sum[i])
		{
			maxn=n_sum[i];
			k=i;
		}
	}
	pk[1]=k+'A';
	n_sum[k]--;
	for(int i=0;i<n;i++)
	{
		if(n_sum[i]*2+2<=ss);
		else return false;
	}

	for(int i=0;i<n;i++)sum[i]=n_sum[i];
	ss--;
	ss--;
	return true;
}
bool pick_one()
{
	if(ss<1)return false;
	for(int i=0;i<n;i++)n_sum[i]=sum[i];
	int maxn=-1,k=-1;
	for(int i=0;i<n;i++)
	{
		if(maxn<n_sum[i])
		{
			maxn=n_sum[i];
			k=i;
		}
	}
	n_sum[k]--;
	pk[0]=k+'A';
	for(int i=0;i<n;i++)
	{
		if(n_sum[i]*2+1<=ss);
		else return false;
	}
	for(int i=0;i<n;i++)sum[i]=n_sum[i];
	ss--;
	return true;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int cas=0;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ss=0;
		for(int i=0;i<n;i++){scanf("%d",&sum[i]);ss+=sum[i];}
		printf("Case #%d: ",++cas);
		while(ss>0)
		{
			if(pick_two())
			{
				printf("%c%c",pk[0],pk[1]);
			}
			else {
				pick_one();
				printf("%c",pk[0]);
			}
			if(ss>0)printf(" ");
			else printf("\n");
		}
	}
}