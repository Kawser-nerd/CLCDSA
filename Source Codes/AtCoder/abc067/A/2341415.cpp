#include <iostream>
using namespace std;

int main(void) {
	// your code goes here
	
	int a,b;
	
	cin >> a >> b;
	
	if(a%3==0 || b%3==0 || (a+b)%3==0) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}