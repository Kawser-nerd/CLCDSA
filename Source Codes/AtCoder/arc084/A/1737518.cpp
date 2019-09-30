#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#define int long long
using namespace std;

int n;
int a[100000];
int b[100000];
int c[100000];

signed main()
{
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) cin >> b[i];
	for (i = 0; i < n; i++) cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	
	static int x[100001] = {0};
	for (i = 0; i < n; i++) {
		int id = upper_bound(c, c + n, b[i]) - c;
		x[i] = n - id;
	}
	for (i = n - 1; i >= 0; i--) x[i] += x[i + 1];
	
	int ans = 0;
	for (i = 0; i < n; i++) {
		int id = upper_bound(b, b + n, a[i]) - b;
		ans += x[id];
	}
	cout << ans << endl;
	
	return 0;
}