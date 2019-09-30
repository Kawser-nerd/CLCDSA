#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;

	int a = 1;
	for( int i = 0; i < n; i++ ) {
		if( a < k ) {
			a = a * 2;
		}
		else {
			a = a + k;
		}
	}

	std::cout << a << std::endl;
	return 0;
}