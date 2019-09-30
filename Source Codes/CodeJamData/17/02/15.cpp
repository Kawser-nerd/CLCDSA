// Google Code Jam 2017, Qualification - problem B
// "Tidy Numbers"
// Andras Eles, Veszprem, Hungary, 2017.04.08.
#include <iostream>
using namespace std;

typedef unsigned long long int uint64;

void solveProblem (void)
{
	uint64 N;
	cin >> N;
	unsigned d[64];
	unsigned dc = 0;
	{
		uint64 Nc = N;
		while (Nc)
		{
			d[dc] = Nc % 10;
			Nc /= 10;
			dc++;
		}
	}
	uint64 tp = 1;
	bool foundwrong = false;
	uint64 tptodiv = 1;
	for (unsigned i=1;i<dc;i++)
	{
		if (d[i] > d[i-1])
		{
			foundwrong = true;
		}
		if (d[i] < d[i-1] && foundwrong)
		{
			foundwrong = false;
			tptodiv = tp;
		}
		tp *= 10;
	}
	if (foundwrong)
	{
		tptodiv = tp;
	}
	if (tptodiv > 1)
	{
		cout << N - (N % tptodiv) - 1;
	}
	else
	{
		cout << N;
	}
	cout << endl;
}

int main (int argc, char** argv)
{
	int T;
	cin >> T;
	for (int t=1;t<=T;t++)
	{
		cout << "Case #" << t << ": " << flush;
		solveProblem();
	}
	return 0;
}
