#include <iostream>

using namespace std;



int main() {
	int n,x;
	cin >> n >> x;

	cout << max(0,min(n-x,x-1)) << endl; 

	return 0;
}