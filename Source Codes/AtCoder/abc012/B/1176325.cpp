#include<iostream>
using namespace std;
int main() {
	int x, a, b, c;
	cin >> x;
	c = x % 60;
	a = (x - (x % 3600)) / 3600;
	b = (x - c - (3600 * a)) / 60;
	if (a < 10)cout << 0;
	cout << a << ':';
	if (b < 10)cout << 0;
	cout << b << ':';
	if (c < 10)cout << 0;
	cout << c << '\n';
}