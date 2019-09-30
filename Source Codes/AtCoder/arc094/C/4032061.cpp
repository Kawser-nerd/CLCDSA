#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long t, a, b, sum = 0, mini = INT_MAX;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		sum += a;
		if (a > b)
			mini = min(mini, b);
	}
	if (mini == INT_MAX)
		cout << 0 << endl;
	else
	cout << sum - mini << endl;
	return 0;
}