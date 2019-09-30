#include <iostream>
using namespace std;
int main() {
	int N;
	long long a[10001];
	int b[10001];
	int ans = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		while (a[i]>0)
		{
			if (a[i] % 2 == 0) {
				a[i] /= 2;
				cnt++;
			}
			else {
				b[i] = cnt;
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		ans += b[i];
	}

	cout << ans << endl;

	return 0;
}