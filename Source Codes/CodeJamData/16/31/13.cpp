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

vector<int> P(26);

void runtestcase()
{	
	int N;
	ein >> N;
	for (int n=0;n<N;n++)
		ein >> P[n];

	int su = 10;
	while (su>0)
	{
		int mP = 0;
		int index = -1;
		int sind = -1;
		su = 0;
		for (int n=0;n<N;n++)
		{
			su += P[n];
			if (P[n] == mP)
			{
				sind = n;
			}
			if (P[n] > mP)
			{
				mP = P[n];
				index = n;
				sind = -1;
			}
		}
		if (su == 0)
			return;

		if ((su == 2 * mP) && (sind != -1))
		{
			aus << char(index+65) << char(sind+65) << " ";
			P[index]--;
			P[sind]--;
		}
		else
		{
			aus << char(index+65) << " ";
			P[index]--;
		}
	}
}

void main()
{
	ein.open("A-large.in");
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