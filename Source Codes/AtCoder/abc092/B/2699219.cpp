#include <iostream>

int main()
{
	int n, d, x;
	std::cin >> n >> d >> x;

	int ans = x;
	for( int i = 0; i < n; i++ ) {
		int a;
		std::cin >> a;
		for( int j = 1 ; j <= d; j += a ) {
			ans += 1;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}