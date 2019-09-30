#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool get_if_win(long a, long b)
{
	long h,l;
	
	if (a == b)
	{
		return false;
	}
	else
	{
		l = a<b?a:b;
		h = a<b?b:a;
		if ( h >= 2*l )
		{
			return true;
		}
		else
		{
			return !(get_if_win(h-l,l));
		}
	}
}

long get_max_b(long a,long lb,long ub)
{
	long mb;
	
	if ( ub - lb <= 1 )
	{
		if ( !get_if_win(a,ub) )
		{
			return ub;
		}
		else
		{
			return lb;
		}
	}
	else
	{
		mb = ( lb + ub ) / 2;
		if ( get_if_win(a,mb) )
		{
			return (get_max_b(a,lb,mb));
		}
		else
		{
			return (get_max_b(a,mb,ub));
		}
	}
}

int main()
{
	int t,T;
	long long win_cnt;
	
	long A1,A2,B1,B2,a,min_b,max_b;
	bool A_turn;
	
	cin >> T;
	
	for ( t = 0; t < T; t++ )
	{
		cin >> A1 >> A2 >> B1 >> B2;
		
		win_cnt = 0;
		for ( a = A1; a <= A2; a++ )
		{
			max_b = get_max_b(a,a,2*a-1);
			min_b = max_b - a + 1;
			
			win_cnt += (B2 - B1 + 1);
			if ( !(max_b < B1) && !(min_b > B2) )
			{
				min_b = min_b<B1?B1:min_b;
				max_b = max_b<B2?max_b:B2;
				win_cnt -= (max_b - min_b + 1);
			}
		}
		
		cout << "Case #" << t + 1 << ": " << win_cnt << "\n";
	}
	
	return 0;
}