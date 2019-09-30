#include <iostream>
using namespace std;
int main() {
	int R;
	cin >> R;
	cout << (R < 1200 ? "ABC" : (R < 2800 ? "ARC" : "AGC"));
	return 0;
}