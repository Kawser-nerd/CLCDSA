#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	//freopen("B-small.in", "r", stdin);
	//freopen("B-small.out", "w", stdout);
	
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		int n;
		int L, P, C;
		cin >> L >> P >> C;
		double x = (double)(P - 1) / L;
		int res = 0;
		if (P > 1LL * L * C)
		{
			x = log(x) / log(C + .0);
			cerr << x << endl;
			res = (log(x) / log(2.) + 2 - 0.99999999999);
		}
		cout << "Case #" << test << ": " << res << endl;
	}
	
	return 0;
}