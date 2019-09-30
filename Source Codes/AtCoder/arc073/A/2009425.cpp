#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

int n, t;
int a[200005];
int main()
{
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long sum = 0;
	for(int i = 2; i <= n; i++)
	{
		int ant = a[i] - a[i-1];
		if(ant < t) sum += ant;
		else sum += t;
	}
	printf("%lld\n", sum + t);
}