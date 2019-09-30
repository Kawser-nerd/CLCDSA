#include <iostream>

int main()
{
	unsigned int a, b;
	std::cin >> a >> b;

	int cake[16] = { 0 };

	// ????????????
	int getCake = 1;

	while ( ( a > 0 ) && ( b > 0 ) )
	{
		int prevA = a;
		int prevB = b;
		for ( int i = 0; i < 16; i++ )
		{
			int prev = cake[(i + 15) % 16];
			int next = cake[(i +  1) % 16];

			// ??????
			if ( ( ( prev != getCake ) && ( next != getCake ) )
				 && ( cake[i] == 0 )	//	???????
				)
			{
				if ( getCake == 1 )
				{
					if ( a > 0 )
					{
						a--;
						cake[i] = getCake;
					}
				}
				else
				{
					if ( b > 0 )
					{
						b--;
						cake[i] = getCake;
					}
				}
			}
			else
			{
				// ????????
			}
			getCake *= -1;
		}

		if ( ( prevA == a ) || ( prevB == b ) )
		{
			// ?????????????????????????
			break;
		}
	}

	// ??????
	if ( ( a == 0 ) && ( b == 0 ) )
	{
		std::cout << "Yay!" << std::endl;
	}
	else
	{
		std::cout << ":(" << std::endl;
	}

	return ( 0 );
}