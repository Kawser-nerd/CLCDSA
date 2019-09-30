#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int>A(3);
	for (int i = 0; i < 3; i++)cin >> A[i];

	int M = max({A[0],A[1],A[2]});
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		ans += (M - A[i]) / 2; A[i] += 2 * ((M - A[i]) / 2);
	}

	sort(A.begin(), A.end());

	if (A[0] == A[1] && A[1] == A[2])cout << ans << endl;
	else if(A[0]==A[1] && A[1]!=A[2])cout << ans + 1 << endl;
	else cout << ans + 2 << endl;

	return 0;
}