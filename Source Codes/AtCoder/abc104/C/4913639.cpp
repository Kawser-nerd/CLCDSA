#include <iostream>
#include <vector>

using myPair = std::pair<long long, long long>;

int main()
{
	long long D, G;
	std::cin >> D >> G;

	std::vector<myPair> v;
	for ( int i = 0; i < D; i++ )
	{
		long long p, c;
		std::cin >> p >> c;
		v.emplace_back( std::make_pair( p, c ) );
	}


	long long totalQ = 0;	//	??????

	std::vector<long long> vD( 1000 );	//	????????????????

	for ( int i = v.size() - 1; i >= 0; i-- )
	{
		for ( int j = 0; j < v[i].first; j++ )
		{
			long long tmpScore = ( ( i + 1 ) * ( j + 1 ) ) * 100;
			if ( j == v[i].first - 1 )	//	Pi??????
			{
				tmpScore += v[i].second;	//	??????????
			}

			for ( int k = totalQ + j; k > j; k-- )	//	???????????????????????
			{
				if ( vD[k] < vD[k - (j + 1)] + tmpScore )
				{
					vD[k] = vD[k - (j + 1)] + tmpScore;
				}
			}
			if ( vD[j] < tmpScore )
			{
				vD[j] = tmpScore;
			}
		}

		totalQ += v[i].first;	//	?????
	}

	for ( int i = 0; i < vD.size(); i++ )
	{
		if ( vD[i] >= G )
		{
			std::cout << i + 1 << std::endl;
			break;
		}
	}

	return ( 0 );
}