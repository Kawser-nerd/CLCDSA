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

int n;
int a[3000];
set<pair<int, char>> s;

int main()
{
	int i, j, k;
	int T, TT;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>TT;
	for(T=1;T<=TT;T++)
	{
		cin>>n;
		for(i=0;i<n;i++) scanf("%d", &a[i]);
		printf("Case #%d: ", T);
		while(1)
		{
			int ma=-1, mai;
			int cnt=0;
			for(i=0;i<n;i++)
			{
				if(ma < a[i]) ma=a[i], mai=i;
				if(a[i]) cnt++;
			}
			if(ma == 0) break;
			if(cnt != 2)
			{
				printf("%c ", mai+'A');
				a[mai]--;
			}
			else
			{
				pii x(-1, -1), y;
				for(i=0;i<n;i++)
				{
					if(a[i] && x.first == -1) x=pii(i, a[i]);
					else if(a[i]) y=pii(i, a[i]);
				}
				if(x.second < y.second) swap(x, y);
				if(x.second != y.second)
				{
					printf("%c ", x.first+'A');
					a[x.first]--;
				}
				else printf("%c%c ", x.first+'A', y.first+'A'), a[x.first]--, a[y.first]--;
			}
		}
		printf("\n");
	}
	return 0;
}
//*/