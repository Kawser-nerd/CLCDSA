#include <iostream>
#include <math.h>
using namespace std;
inline int num(int b) {
	int cnt = 0;
	while (b > 0) {
		b /= 10;
		cnt++;
	}
	return cnt;
}

bool Is_sqr(int n) {
	bool f = false;

	for (int i = 1; i <=sqrt(n); i++)
	{
		if (i*i == n)
			f = true;
	}
	return f;
}

int main() {
	int a, b;
	cin >> a >> b;

	a = a * pow(10, num(b));
	a += b;

	if (Is_sqr(a))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}