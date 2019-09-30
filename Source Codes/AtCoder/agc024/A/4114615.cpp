#include <iostream>
using namespace std;
int main() {
	long long A, B, C, K;
	cin >> A >> B >> C >> K;
	cout << (A - B) * (K % 2 == 0 ? 1 : -1) << endl;
	return 0;
}