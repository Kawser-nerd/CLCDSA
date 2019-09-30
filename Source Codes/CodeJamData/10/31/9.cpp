#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	//freopen("A-small.in", "r", stdin);
	//freopen("A-small.out", "w", stdout);
	
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		int n;
		pii p[1 << 10];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i].first >> p[i].second;
			
		sort(p, p + n);
		int res = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < i; j++)
			if (p[i].second < p[j].second) res++;
		cout << "Case #" << test << ": " << res << endl;
	}
	
	return 0;
}