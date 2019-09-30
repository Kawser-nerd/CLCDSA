#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,x,y,dp[5][10010],cnt[200],h;
string a;

int main()
{
	int i;
	cin>>n>>m>>x;
	if(n<m) swap(n,m);
	if(n<x) swap(n,x);
	n==m+x?puts("Yes"):puts("No");
}