#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long N, tmp = 1;
	cin >> N;
	for(long long i = 1; i <= N; i++){
		tmp *= i;
		tmp %= 1000000007;
	}
	cout << tmp << endl;
}