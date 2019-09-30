#include <iostream>
#include <string>
using namespace std;
int main() {
	int A[4] = { 0 };
	int N, ans = 0;
	char s;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == 'P') {
			A[0] = 1;
		}
		if (s == 'W') {
			A[1] = 1;
		}
		if (s == 'G') {
			A[2] = 1;
		}
		if (s == 'Y') {
			A[3] = 1;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		ans += A[i];
	}

	if (ans == 3) {
		cout << "Three" << endl;
	}
	else {
		cout << "Four" << endl;
	}

	return 0;
}