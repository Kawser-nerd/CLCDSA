#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int N, M;
	cin >> N>> M;
	vector<pair<int,int>> ab(M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ab[i] = make_pair(a, b);
	}
	int output = 0;

	for (int i = 0; i < M; i++)
	{
		vector<int> visited(N+1);
		visited[ab[i].first] = 1;
		for (int count = 0; count < M;count++)
		{
			for (int j = 0; j < M; j++)
			{
				if (j == i)continue;
				if (visited[ab[j].first] == 1)
				{
					visited[ab[j].second] = 1;
				}
				if (visited[ab[j].second] == 1)
				{
					visited[ab[j].first] = 1;
				}

			}
		}
		if (visited[ab[i].second] != 0)
		{
			output++;
		}
		
	}

	cout << M-output << endl;
	return 0;
}