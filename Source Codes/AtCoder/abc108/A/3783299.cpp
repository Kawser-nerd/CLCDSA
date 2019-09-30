#include<iostream>
using namespace std;

int main() {

	int K,i;
	int odd_c=0,even_c=0;
	cin >> K;

	for (i = 1; i <= K; i++) {
		if (i % 2 == 0) {
			even_c++;
		}
		else {
			odd_c++;
		}
	}

	cout << odd_c * even_c;

	return 0;
}