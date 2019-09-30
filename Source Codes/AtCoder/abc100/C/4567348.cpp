#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N;
	cin >> N;
	int out = 0;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		while(a > 0 && a % 2 == 0) {
			out++;
			a /= 2;
		}
	}
	cout << out << endl;
}