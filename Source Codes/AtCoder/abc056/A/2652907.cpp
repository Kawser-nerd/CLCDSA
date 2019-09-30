#include <iostream>

int main()
{
	char a, b;
	std::cin >> a >> b;

	char ans;

	if( a == 'H' and b == 'H' )  ans = 'H';
	if( a == 'D' and b == 'H' )  ans = 'D';
	if( a == 'H' and b == 'D' )  ans = 'D';
	if( a == 'D' and b == 'D' )  ans = 'H';

	std::cout << ans << std::endl;

	return 0;
}