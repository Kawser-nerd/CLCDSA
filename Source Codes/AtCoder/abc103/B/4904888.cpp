#include <iostream>
#include <string>

int main()
{
	std::string s, t;
	std::cin >> s >> t;

	bool bSame = false;

	for ( int i = 0; i < s.length(); i++ )
	{
		if ( s == t )
		{
			bSame = true;
			break;
		}

		s.insert( s.begin(), s.back() );	//	??????????????
		s.erase( s.length() - 1 );			//	??????????
	}

	if ( bSame )
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	return ( 0 );
}