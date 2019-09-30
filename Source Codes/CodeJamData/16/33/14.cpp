#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>
#include <string>

using namespace std;

int t,T;
ifstream ein;
ofstream aus;

#define ULL unsigned long long



void runtestcase()
{	
	int J, P, S, K;
	ein >> J >> P >> S >> K;

	aus << min(S, K) * J * P;
	
	for (int j = 1; j <= J; j++)
	{
		for (int p = 1; p <= P; p++)
		{
			for (int s = 1; s <= S; s++)
			{
				if (((j+p+s) % S) < min(S,K))
				{
					aus << endl << j << " " << p << " " << s;
				}
			}
		}
	}
}

void main()
{
	ein.open("C-large.in");
	aus.open("ausgabe.txt");

	ein >> T;
	for (t = 1; t <= T; t++)
	{
		printf("%d\n", t);
		aus << "Case #" << t << ": ";
		runtestcase();
		aus << endl;
	}

	aus.close();
	ein.close();
}