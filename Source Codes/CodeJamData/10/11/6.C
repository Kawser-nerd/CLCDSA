#include <iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	int t,T;
	bool R_line,B_line;
	bool r_l,b_l;
	
	int n_v,n_h,N,k,K;
	char inp_l[60];
	char table[60][60];
	bool gravity_end;
	
	cin >> T;
	
	for ( t = 0; t < T; t++ )
	{
		
		// input the data
		cin >> N >> K;
		for ( n_v = 0; n_v < N; n_v++ )
		{
			cin >> inp_l;
			for ( n_h = 0; n_h < N; n_h++ )
			{
				table[n_v][n_h] = inp_l[n_h];
			}
		}
		
		// rotate the board
		gravity_end = false;
		while ( !gravity_end )
		{
			gravity_end = true;
			for ( n_v = 0; n_v < N; n_v++ )
			{
				for ( n_h = N - 2; n_h >= 0; n_h-- )
				{
					if ( !(table[n_v][n_h] == '.') && (table[n_v][n_h + 1] == '.') )
					{
						table[n_v][n_h + 1] = table[n_v][n_h];
						table[n_v][n_h] = '.';
						gravity_end = false;
					}
				}
			}
		}
		
		// check for filled lines
		R_line = false;
		B_line = false;
		
		 // horizontal
		for ( n_v = 0; n_v < N; n_v++ )
		{
			for ( n_h = 0; n_h < N - K + 1; n_h++ )
			{
				r_l = true;
				b_l = true;
				for ( k = 0; k < K; k++ )
				{
					if ( !(table[n_v][n_h+k] == 'R') ) r_l = false;
					if ( !(table[n_v][n_h+k] == 'B') ) b_l = false;
				}
				if ( r_l ) R_line = true;
				if ( b_l ) B_line = true;
			}
		}
		
		// vertical
		for ( n_v = 0; n_v < N - K + 1; n_v++ )
		{
			for ( n_h = 0; n_h < N; n_h++ )
			{
				r_l = true;
				b_l = true;
				for ( k = 0; k < K; k++ )
				{
					if ( !(table[n_v+k][n_h] == 'R') ) r_l = false;
					if ( !(table[n_v+k][n_h] == 'B') ) b_l = false;
				}
				if ( r_l ) R_line = true;
				if ( b_l ) B_line = true;
			}
		}
		
		// diagonal+
		for ( n_v = 0; n_v < N - K + 1; n_v++ )
		{
			for ( n_h = 0; n_h < N - K + 1; n_h++ )
			{
				r_l = true;
				b_l = true;
				for ( k = 0; k < K; k++ )
				{
					if ( !(table[n_v+k][n_h+k] == 'R') ) r_l = false;
					if ( !(table[n_v+k][n_h+k] == 'B') ) b_l = false;
				}
				if ( r_l ) R_line = true;
				if ( b_l ) B_line = true;
			}
		}
		
		// diagonal-;
		for ( n_v = 0; n_v < N - K + 1; n_v++ )
		{
			for ( n_h = K - 1; n_h < N; n_h++ )
			{
				r_l = true;
				b_l = true;
				for ( k = 0; k < K; k++ )
				{
					if ( !(table[n_v+k][n_h-k] == 'R') ) r_l = false;
					if ( !(table[n_v+k][n_h-k] == 'B') ) b_l = false;
				}
				if ( r_l ) R_line = true;
				if ( b_l ) B_line = true;
			}
		}
		
		// output results
		if ( R_line && B_line )
		{
			cout << "Case #" << t + 1 << ": Both\n";
		}
		else if ( R_line && !B_line )
		{
			cout << "Case #" << t + 1 << ": Red\n";
		}
		else if ( !R_line && B_line )
		{
			cout << "Case #" << t + 1 << ": Blue\n";
		}
		else if ( !R_line && !B_line )
		{
			cout << "Case #" << t + 1 << ": Neither\n";
		}
		
	}
	
	return 0;
}