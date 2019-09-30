#include <iostream>
using namespace std;
int main() {
	int time[100] = { 0 };

	int A, B, C, D;
	int cnt=0;

	cin >> A >> B >> C >> D;

	for (int i = A; i < B; i++)
	{
		time[i] = 1;
	}
	for (int i = C; i < D; i++)
	{
		if (time[i] != 0)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}