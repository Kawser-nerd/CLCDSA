#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	int N;
	int num;
	while (cin >> N)
	{
		a = b = c = 0;
		while (N--)
		{
			cin >> num;
			if (num % 4 == 0) a++;
			else if (num % 2 == 0) b++;
			else c++;
		}
		if (b == 0)
		{
			if (a >= c - 1) cout << "Yes" << endl;
			else cout << "No" << endl;
			continue;
		}

		if (a >= c) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}