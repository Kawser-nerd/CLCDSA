#include <iostream>

using namespace std;


int main(void)
{
	int N, T;

	cin >> N >> T;

	int cost = 1001;
	for(int i = 0; i < N; ++i)
	{
		int ci, ti;
		cin >> ci >> ti;
		if(T >= ti)
		{
			if(cost >= ci)
			{
				cost = ci;
			}
		}
	}

	if(cost == 1001)
	{
		cout << "TLE" << endl;
	}
	else
	{
		cout << cost << endl;
	}

	return 0;
}