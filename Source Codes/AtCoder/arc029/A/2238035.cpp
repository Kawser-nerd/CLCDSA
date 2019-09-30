#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	int NIKU[ 4 ];
	for( int i = 0; i < N; i ++)
	{
		cin >> NIKU [ i ];
	}

	int min = 9999;
	for( int i = 0; i < ( 1 << N ); i ++ )
	{
		int a = 0;
		int b = 0;
		for( int j = 0; j < N; j ++ )
		{
			if( i & ( 1 << j ) )
			{
				a += NIKU[j];
			}
			else
			{
				b += NIKU[j];
			}
		}
		int total = a >= b ? a : b;
		//cout << a << " " << b << " "<< total << endl;
		if( total < min )
		{
			min = total;
		}
	}

	cout << min << endl;

	return 0;
}