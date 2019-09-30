#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int numCase;
	cin >> numCase;
	int i, j, n;
	long long c;
	for (i = 0; i < numCase; i++)
	{
		cin >> n;
		vector<long long> array1, array2;
		for (j = 0; j < n; j++)
		{
			cin >> c;
			array1.push_back(c);
		}
		for (j = 0; j < n; j++)
		{
			cin >> c;
			array2.push_back(c);
		}
		sort(array1.begin(), array1.end());
		sort(array2.begin(), array2.end(), greater<long long>());
		long long ans = 0;
		for (j = 0; j < n; j++)
			ans += (array1[j] * array2[j]);
		cout << "Case #" << (i+1) << ": " << ans << endl;
	}
	return 0;
}
