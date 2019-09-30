// Google Code Jam 2017, Qualification - problem A
// "Oversized Pancake Flipper"
// Andras Eles, Veszprem, Hungary, 2017.04.08.
#include <iostream>
#include <string>
using namespace std;

void solveProblem (void)
{
	string S;
	unsigned K;
	cin >> S >> K;
	unsigned N = 0;
	for (unsigned top=S.size()-1;top>=K-1;top--)
	{
		if (S[top] == '-')
		{
			for (unsigned i=0;i<K;i++)
			{
				S[top-i] = (S[top-i] == '-' ? '+' : '-');
			}
			N++;
		}
	}
	bool impossible = false;
	for (unsigned i=0;i<K;i++)
	{
		if (S[i] == '-')
		{
			impossible = true;
			break;
		}
	}
	if (impossible)
	{
		cout << "IMPOSSIBLE";
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
