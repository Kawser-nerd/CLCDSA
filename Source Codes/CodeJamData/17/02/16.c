#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		string N;
		cin >> N;
		int i,j,k;
		for(i=N.size()-1; i>0; i--)
		{
			if (N[i] < N[i-1])
			{
				N[i-1]--;
				for(j=i; j<N.size(); j++)
					N[j] = '9';
			}
		}
		if (N[0] == '0')
			N = N.substr(1);
		printf("Case #%d: %s\n", cc, N.c_str());
	}
}
