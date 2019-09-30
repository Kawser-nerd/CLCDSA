#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100010];
int main()
{
	int n,sumj=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2==1) sumj++;
	}
	if(sumj%2==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}