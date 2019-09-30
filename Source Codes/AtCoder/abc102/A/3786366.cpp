#include<iostream>
using namespace std;

int main() {

	int n,i,ans;
	cin >> n;

	for (i = n; i <= (n*2)/2; i++) {
		if (i % 2 == 0 && i%n == 0) {
			ans = i;
			break;
		}
		else if (i = (n * 2) / 2) {
			ans = n * 2;
		}
	}

	cout << ans;

	return 0;
} ./Main.cpp:14:14: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
                else if (i = (n * 2) / 2) {
                         ~~^~~~~~~~~~~~~
./Main.cpp:14:14: note: place parentheses around the assignment to silence this warning
                else if (i = (n * 2) / 2) {
                           ^
                         (              )
./Main.cpp:14:14: note: use '==' to turn this assignment into an equality comparison
                else if (i = (n * 2) / 2) {
                           ^
                           ==
1 warning generated.