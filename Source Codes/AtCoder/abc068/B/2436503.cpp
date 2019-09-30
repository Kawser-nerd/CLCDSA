#include <iostream>
using namespace std;

int main() {
	int n, tmp=1;
	cin >> n;
	while(tmp <= n){
		tmp *= 2;
	}
	tmp /= 2;
	cout << tmp;
	return 0;
}