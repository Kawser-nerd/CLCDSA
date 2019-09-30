#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int N, M;
int P[100005], Y[100005];
vector<int> yd[100005];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> P[i] >> Y[i];
		yd[P[i]].push_back(Y[i]);

	}

	for (int i = 0; i < N; i++)
		sort(yd[i + 1].begin(), yd[i + 1].end());
	for (int i = 0; i < M; i++)
	{
		printf("%06d", P[i]);
		printf("%06d\n", lower_bound(yd[P[i]].begin(), yd[P[i]].end(), Y[i]) - yd[P[i]].begin() + 1);
	}

	return 0;
} ./Main.cpp:25:20: warning: format specifies type 'int' but the argument has type 'long' [-Wformat]
                printf("%06d\n", lower_bound(yd[P[i]].begin(), yd[P[i]].end(), Y[i]) - yd[P[i]].begin() + 1);
                        ~~~~     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                        %06ld
1 warning generated.