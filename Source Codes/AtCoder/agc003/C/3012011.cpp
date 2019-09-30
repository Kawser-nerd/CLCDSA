#include<iostream>
#include<algorithm>
#include<iomanip>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <new>
#include <cmath>
#include<fstream>
using namespace std;
#define Precision(i) cout << fixed << setprecision(i)
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
const ll N = 1e5 + 100, MOD = 1e9 + 7, INF = 1e17, SQ = 350, LOG = 20;
ll n, m, x1, x2, d, z , t, sum,y, maxi,mini, ans, ptr, x, q, a[N], b[N], k;
map <ll, int> mp;
int main()  
{
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		mp[a[i]] = i % 2;
	}
	for (int i = 0; i < n; i++)
	{
		if (mp[b[i]] != i % 2) ans++;
	}
	cout << ans / 2;
}