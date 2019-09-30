#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	char a, b;	cin >> a >> b;

	if (a == 'H') {
		if (b == 'D') {
			cout << 'D' << endl;
			return 0;
		}
		cout << 'H' << endl;
		return 0;
	}
	
	if (b == 'H') {
		cout << 'D' << endl;
		return 0;
	}
	cout << 'H' << endl;
	return 0;
}