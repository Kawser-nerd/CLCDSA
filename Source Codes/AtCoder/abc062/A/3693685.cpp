#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a(13, 0);
	a[1] = 1; 
	a[2] = 3; 
	a[3] = 1; 
	a[4] = 2; 
	a[5] = 1; 
	a[6] = 2; 
	a[7] = 1; 
	a[8] = 1; 
	a[9] = 2; 
	a[10] = 1; 
	a[11] = 2; 
	a[12] = 1; 

	int x, y; cin >> x >> y;
	if(a[x] == a[y]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}