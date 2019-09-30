#include<iostream>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	n%k == 0 ? cout << "0" : cout << "1";
	return 0;
}