#include <iostream>
#include <stdlib.h>
using namespace std;

const long long inf = 2000000000;

struct cost_str
{
	long long c[12];
} costs[2050];

int main()
{
	int t,T;
	int P,N;
	long M[1024];
	
	int i,j;
	long long cost_buy, cost_not_buy, ticket_cost;
	
	cin >> T;
	
	for ( t = 0; t < T; t++ )
	{
		// input the data
		cin >> P;
		
		N = 1;
		for ( i = 0; i < P; i++ )
		{
			N *= 2;
		}
		
		for ( i = 0; i < N; i++ )
		{
			cin >> M[N - 1 - i];
		}
		
		// initialize the cost array
		for ( i = N; i < 2*N; i++ )
		{
			for ( j = 0; j < P - M[i - N]; j++ )
			{
				costs[i].c[j] = inf;
			}
			for ( j = P - M[i - N]; j <= P; j++ )
			{
				costs[i].c[j] = 0;
			}
		}
		
		// misc: initialize border cases to zeros
		for ( i = 0; i < 2*N; i++ )
		{
			costs[i].c[P+1] = 0;
		}
		
		// compute costs down the tree
		for ( i = N - 1; i > 0; i-- )
		{
			cin >> ticket_cost;
			for ( j = 0; j <= P; j++ )
			{
				cost_not_buy = costs[2*i].c[j] + costs[2*i+1].c[j];
				cost_buy = costs[2*i].c[j+1] + costs[2*i+1].c[j+1] + ticket_cost;
				costs[i].c[j] = cost_buy<cost_not_buy?cost_buy:cost_not_buy;
				
				if ( costs[i].c[j] > inf ) costs[i].c[j] = inf;
			}
		}
		
		/*
		// debug
		for ( i = 0; i < N; i++ )
		{
			cout << M[i] << " ";
		}
		cout << "\n\n";
		
		for ( i = 1; i < 2*N; i++ )
		{
			for ( j = 0; j <= P; j++ )
			{
				cout << costs[i].c[j] << " ";
			}
			cout << "\n";
		}
		 */
		
		// output the final result
		cout << "Case #" << t + 1 << ": " << costs[1].c[0] << "\n";
	}
	
	return 0;
}