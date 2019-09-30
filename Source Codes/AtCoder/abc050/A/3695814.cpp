#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	char op;
	cin >> a;
	cin >> op;
	cin >> b;
	if(op == '+') {
		cout << a + b << endl;
	} else {
		cout << a - b << endl;
	}
}