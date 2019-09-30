#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
	int W, a, b;
	cin >> W >> a >> b;
	if(a > b) swap(a, b);
	if (b <= a + W && b + W >= a + W) cout << '0' << endl;
	else {
		if(b > a) cout << b - a - W << endl;
		else cout << a - b - W << endl;
	}
}