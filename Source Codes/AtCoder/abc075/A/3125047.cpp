#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int A[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> A[i];
	}

	sort(A, A + 3);

	if (A[0] == A[1]) {
		cout << A[2] << endl;
	}
	else {
		cout << A[0] << endl;
	}

	return 0;
}