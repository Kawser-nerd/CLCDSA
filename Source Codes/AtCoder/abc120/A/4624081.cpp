#include<iostream>
using namespace std;
#include<vector>
#include<string>

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int kais = 0;
	if (B / A < C) {
		cout << B / A;
	}
	else {
		cout << C;
	}
	system("pause");
	return 0;
}