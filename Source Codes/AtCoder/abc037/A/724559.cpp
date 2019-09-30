#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int ans = C / min(A, B);
	cout << ans << endl;
}