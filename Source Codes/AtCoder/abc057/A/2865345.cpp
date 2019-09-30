#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int A, B;	cin >> A >> B;

	if (A + B < 24) {
		cout << A + B << endl;
		return 0;
	}
	cout << (A + B) - 24 << endl;

	return 0;
}