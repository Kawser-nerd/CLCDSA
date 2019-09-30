#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	cout << c / min(a, b) << endl;
}