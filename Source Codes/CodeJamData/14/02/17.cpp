#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("b-large.in", "r", stdin); 
	freopen("b-large.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		double C, F, X;
		cin >> C >> F >> X;
		
		double ans = 1e18, currentTime = 0, rate = 2;
		for (int farm = 0; farm <= 10100100; farm++)
		{
			double neededTime = currentTime + X / rate;
			ans = min(ans, neededTime);
			currentTime += C / rate;
			rate += F;
		}
		
		printf("Case #%d: %.9lf\n", noTest, ans);
	}
}
