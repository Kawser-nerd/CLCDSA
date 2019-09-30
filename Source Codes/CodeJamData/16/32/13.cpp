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
	ULL B, M;
	bool f = false;
	ein >> B >> M;
	if (M > (ULL(1) << (B-2)))
	{
		aus << "IMPOSSIBLE";
		return;
	}
	aus << "POSSIBLE" << endl;
	aus << "0";

	if (M == (ULL(1) << (B-2)))
	{
		f = true;
		M--;
	}

	for (ULL i=2; i<=B-1; i++)
	{
		if (M & (ULL(1) << (B-i-1)))
		{
			aus << "1";
		}
		else
		{
			aus << "0";
		}
	}
	if (f)
	{
		aus << "1";
	}
	else
	{
		aus << "0";
	}
	
	for (ULL i=2; i<=B; i++)
	{
		aus << endl;
		for (ULL j=1; j<=B; j++)
		{
			if (j<=i)
			{
				aus << "0";
			}
			else
			{
				aus << "1";
			}			
		}		
	}
}

void main()
{
	ein.open("B-large.in");
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