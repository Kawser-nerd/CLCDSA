#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("d-large.in", "r", stdin); 
	freopen("d-large.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		double a[1010], b[1010];
		int n;
		
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		
		int warPoint = n;
		for (int i = 1, j = 1; i <= n; i++)
		{
			while (j <= n && a[i] > b[j]) j++;
			if (j > n) break;
			warPoint--;
			j++;
		}
		
		int deceitPoint = 0;
		for (int j = 1, i = 1; j <= n; j++)
		{
			while (i <= n && a[i] < b[j]) i++;
			if (i > n) break;
			deceitPoint++;
			i++;
		}
		
		printf("Case #%d: %d %d\n", noTest, deceitPoint, warPoint);
	}
}
