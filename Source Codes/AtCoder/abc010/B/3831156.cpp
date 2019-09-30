#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		while (tmp % 3 == 2 || tmp % 2 == 0)
		{
			tmp--;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}