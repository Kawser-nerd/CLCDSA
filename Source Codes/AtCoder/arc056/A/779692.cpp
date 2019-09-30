#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, K, L;
	cin >> A >> B >> K >> L;
	long long m = K / L;
	long long s = K % L;
	long long ans = min(m * B + s * A, (m + 1) * B);
	cout << ans << endl;
}