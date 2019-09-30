#include <iostream>
using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	if(a == 'H'){
		cout << b << endl;
	} else {
		if(b == 'D') cout << 'H';
		else cout << 'D';
	}
}