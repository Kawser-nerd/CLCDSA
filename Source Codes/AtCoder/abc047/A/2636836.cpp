#include <iostream>
using namespace std;

int main()
{
	int a, b, c, s;
	cin >> a >> b >> c;

	s = a + b + c;
	if( s == 2*( a + b ) or s == 2*( b + c ) or s == 2*( c + a )) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No"  << endl;
	}

	return 0;
}