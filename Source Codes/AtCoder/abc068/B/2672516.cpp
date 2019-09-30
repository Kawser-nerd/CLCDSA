#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int ans = 1;
	while( ans <= n ) {
		ans = ans * 2;
		if( ans > n ) {
			ans = ans / 2;
			break;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}