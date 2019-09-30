#include <iostream>
using namespace std;

int main()
{
	int N;
	int A[200];

	cin >> N;
	for (int i = 0; i <= 200; i++) cin >> A[i];
	
	int res = 0;

	while (true) {
		bool isOdd = false;

		for (int i = 0; i < N; ++i){
			if (A[i] % 2 != 0) isOdd = true;
		}

		if (isOdd) break;

		for (int i = 0; i < N; ++i) A[i] /= 2;
		
		++res;
	}
	cout << res << endl;
}