#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, A, B;
	int C[110];

	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];

	sort(C, C + N, greater<int>());
	A = 0;
	B = 0;
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) {
			A += C[i];
		}else{
			B += C[i];
		}
	}
	cout << A - B << endl;
}