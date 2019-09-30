#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	bool ans = false;

	for (int i = 0; i <= N / 4; ++i) {
		for (int j = 0; j <= N / 7; ++j) {
			int total = 4*i + 7*j;
			if (total == N) ans = true;
		}
	}
	if (!ans) cout << "No" << endl;
	else cout << "Yes" << endl;
}