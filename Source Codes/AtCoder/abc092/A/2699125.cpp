#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min( a, b ) + min( c, d ) << endl;
	return 0;
}