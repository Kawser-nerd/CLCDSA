#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#define For(i,j,k)	for(int  i=j;i<=k;i++)
#define Dow(i,j,k)	for(int  i=k;i>=j;i--)
#define ll long long
using namespace std;
int n,m,cnt[200001],x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	For(i,1,m)
		{cin>>x>>y;cnt[x]++;cnt[y]++;}
	For(i,1,n)
	if(cnt[i]&1){printf("NO\n");return 0;}
	printf("YES\n");
}