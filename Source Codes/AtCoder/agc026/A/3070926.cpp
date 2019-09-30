#include <iostream>
using namespace std;
int main() {
	int N;
	int a[100];
	int cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (a[i] == a[i + 1]) {
			cnt++;
			i++;
		}
	}

	cout << cnt << endl;

	return 0;
}