#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	if(n <= 59) {
		cout << "Bad\n";
	} else if(60 <= n && n <= 89) {
		cout << "Good\n";
	} else if(90 <= n && n <= 99)  {
		cout << "Great\n";
	} else {
		cout << "Perfect\n";
	}
}