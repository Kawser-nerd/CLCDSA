#include <iostream>

int main()
{
	int d, n;
	std::cin >> d >> n;

	int d0[100];
	int d1[100];
	int d2[100];

	int *dX[3] = { d0, d1, d2 };

	// 100???????????????
	for ( int i = 0; i < 100; i++ )
	{
		d0[i] = i + 1;
	}
	d0[99] = 101;

	// 100?1????????????????
	for ( int i = 0; i < 100; i++ )
	{
		d1[i] = d0[i] * 100;
	}

	// 100?2??????????????
	for ( int i = 0; i < 100; i++ )
	{
		d2[i] = d1[i] * 100;
	}

	std::cout << dX[d][n - 1] << std::endl;

	return ( 0 );
}