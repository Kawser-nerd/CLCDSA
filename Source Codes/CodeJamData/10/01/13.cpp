#include <iostream>

using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		int n, k;
		cin >> n >> k;
		bool ok = true;
		for (int i = 0; i < n; i++) if ((k & (1 << i)) == 0) ok = false;
		cout << "Case #" << test << ": " << (ok ? "ON" : "OFF") << endl;
	}
	
	return 0;
}