// Google Code Jam 2017, Qualification - problem C
// "Bathroom Stalls"
// Andras Eles, Veszprem, Hungary, 2017.04.08.
#include <iostream>
using namespace std;

typedef unsigned long long int uint64;

void solveProblem (void)
{
	uint64 K, N;
	cin >> N >> K;
	uint64 rem = K - 1;
	uint64 b = N + 1, bc = 0, sc = 1;
	do {
		if (rem < bc + sc)
		{
			uint64 const iv = (rem < bc) ? b : (b - 1);
			cout << (iv / 2) << " " << ((iv - 1) / 2);
			break;
		}
		rem -= (bc + sc);
		uint64 const newbc = ((b & 1) ? 2 * bc + sc : bc);
		uint64 const newsc = ((b & 1) ? sc : 2 * sc + bc);
		bc = newbc;
		sc = newsc;
		b /= 2;
	}
	while (true);
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
