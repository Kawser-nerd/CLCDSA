#include <iostream>
#include <algorithm>
 
 
using namespace std;
int main() {
	int n;
	cin >> n;
 
	long a[3 * n];
 
	for (int i = 0; i < n * 3; i++) {
		cin >> a[i]; 
	}
 
	sort(a, a + (3 * n) );
 
	long long count = 0;
	for (int i = 0; i < n; i++) {
		count +=  a[3 * n  - 1 - (i * 2 + 1)] ;
	}
	cout << count << endl;
 
	return 0;
}