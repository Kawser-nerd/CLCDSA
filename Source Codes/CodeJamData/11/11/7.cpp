#include <iostream>
#include <cstdio>

using namespace std;

bool possible (long long tot, long long per)
{
	if (per == 0 || per == 100) return true;
	
	for (int i = 0; i < 2; i ++)
		if (per % 2 == 0)
		{
			per /= 2;
			tot *= 2;
		}

	for (int i = 0; i < 2; i ++)
		if (per % 5 == 0)
		{
			per /= 5;
			tot *= 5;
		}

	tot /= 100;

	return tot > 0;
}

int main ()
{
	int t, ct = 0;

	for (cin >> t; t>0; t --)
	{
		long long n, pd, pg;

		cin >> n >> pd >> pg;

		printf ("Case #%d: ", ++ ct);

		if (pd != 100 && pg == 100 || pd != 0 && pg == 0)
			printf ("Broken\n");
		else
		{
			if (possible(n, pd))
				printf ("Possible\n");
			else
				printf ("Broken\n");
		}
	}

	return 0;
}