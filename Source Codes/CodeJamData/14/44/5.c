#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>

std::vector<std::string> S;
int N, M;
int A[8];
int most;
int count;

void treg(int d)
{
	if (d == M)
	{
		int total = 0;
		for (int i=0; i<N; i++)
		{
			std::set<std::string> V;
			for (int j=0; j<M; j++)
				if (A[j] == i)
				{
					for (int k=0; k<=S[j].length(); k++)
						V.insert(S[j].substr(0, k));
				}
			total += V.size();
		}
		if (total > most)
		{
			most = total;
			count = 1;
		}
		else if (total == most)
		{
			count++;
		}
//		std::cout << total << std::endl;
		return;
	}
	for (int i=0; i<N; i++)
	{
		A[d] = i;
		treg(d+1);
	}
}

int main()
{
	int T;
	std::cin >> T;
	for (int t=1; t<=T; t++)
	{
		std::cin >> M >> N;
		S.clear();
		most = 0;
		count = 0;
		for (int i=0; i<M; i++)
		{
			std::string s;
			std::cin >> s;
			S.push_back(s);
		}
		treg(0);
		printf("Case #%d: %d %d\n", t, most, count);
	}
	return 0;
}
