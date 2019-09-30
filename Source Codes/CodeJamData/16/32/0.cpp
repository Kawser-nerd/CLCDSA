//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll n, m;
int a[100][100];

int main()
{
	int i, j, k;
	int T, TT;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>TT;
	for(T=1;T<=TT;T++)
	{
		printf("Case #%d: ", T);
		cin>>n>>m;
		if(m > (1ll<<(n-2)))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=0;
		for(i=0;i<n-1;i++) for(j=0;j<i;j++) a[j][i]=1;
		if(m == (1ll<<(n-2)))
		{
			for(i=0;i<n-1;i++) a[i][n-1]=1;
		}
		else
		{
			for(i=0;i<n-2;i++)
			{
				if((1ll<<i)&m)
				{
					a[i+1][n-1]=1;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) printf("%d", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
//*/