#include <iostream>
using namespace std;
int main() {
	long long N, S=1;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		S *= i;
		if (S >= 1000000007) {
			S %= 1000000007;
		}
	}

	cout << S << endl;

	return 0;
}