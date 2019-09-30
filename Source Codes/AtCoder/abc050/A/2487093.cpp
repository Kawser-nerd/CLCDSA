#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,dp[5][10010];
char a;
bool ans;

int main()
{
	int i;
	cin>>n>>a>>m;
	if(a=='+') cout<<n+m;
	else cout<<n-m;
}