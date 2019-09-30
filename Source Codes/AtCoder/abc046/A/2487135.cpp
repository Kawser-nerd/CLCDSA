#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,x,y,dp[5][10010],cnt[200],h;
string a;

int main()
{
	int i;
	for(i=1;i<=3;i++)
	{
		cin>>x;
		cnt[x]++;
		if(cnt[x]==1) h++;
	}
	cout<<h;
}