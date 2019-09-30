#include <iostream>
using namespace std;

int main() {
	int a, b, c, k, s, t;
	cin >> a >> b >> c >> k >> s >> t;
	if(s+t >= k) {
		cout << a*s + b*t - c*(s+t) << endl;
	} else {
		cout << a*s + b*t << endl;
	}
}