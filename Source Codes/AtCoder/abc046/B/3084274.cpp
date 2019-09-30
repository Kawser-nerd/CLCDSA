#include <iostream>
#include <math.h>
using namespace std;
int main() {
	long long N, K, ans;
	cin >> N >> K;

	ans = K * pow((K - 1), N-1);

	cout << ans << endl;

	return 0;
}