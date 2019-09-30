#include <iostream>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	if(a <= c && c <= b) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}