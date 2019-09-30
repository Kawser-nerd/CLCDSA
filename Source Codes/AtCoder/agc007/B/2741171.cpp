#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[30005]={0},a[30005]={0},b[30005]={0};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	a[1]=100000;
	for(int i=2;i<=n;i++)a[i]=a[i-1]+30000;
	for(int i=1;i<=n;i++)b[n-i+1]=a[i];
	for(int i=1;i<=n;i++)b[p[i]]+=i;
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<'\n';
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	return 0;
}