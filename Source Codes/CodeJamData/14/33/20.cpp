#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

int T;
int R, C, K;

int run(VI v, int s, int k)
{
	while(k >= K)
	{
		int mink = 1000000;
		int ki = 0;

		if(mink > v[4] - v[0])
		{
			mink = v[4] - v[0];
			ki = 0;
		}
		if(mink > v[6] - v[5])
		{
			mink = v[6] - v[5];
			ki = 1;
		}
		if(mink > v[6] - v[11])
		{
			mink = v[6] - v[11];
			ki = 2;
		}
		if(mink > v[10] - v[0])
		{
			mink = v[10] - v[0];
			ki = 3;
		}

		++mink;

		if(ki == 0)
		{
			if(v[1] == v[2])
			{
				++v[0];
				v[2] += (v[9] > v[2]);
			}
			else
				++v[1];

			if(v[4] == v[5])
			{
				++v[3];
				v[5] += (v[6] > v[5]);
			}
			else
				++v[4];
		}

		if(ki == 1)
		{
			if(v[7] == v[8])
			{
				--v[6];
				v[8] += (v[9] > v[8]);
			}
			else
				++v[7];

			if(v[4] == v[5])
			{
				++v[3];
				v[4] -= (v[0] < v[4]);
			}
			else
				--v[5];
		}

		if(ki == 2)
		{
			if(v[7] == v[8])
			{
				--v[6];
				v[7] -= (v[3] < v[7]);
			}
			else
				--v[8];

			if(v[10] == v[11])
			{
				--v[9];
				v[10] -= (v[0] < v[10]);
			}
			else
				--v[11];
		}

		if(ki == 3)
		{
			if(v[1] == v[2])
			{
				++v[0];
				v[1] -= (v[3] < v[1]);
			}
			else
				--v[2];

			if(v[10] == v[11])
			{
				--v[9];
				v[11] += (v[6] > v[11]);
			}
			else
				++v[10];
		}

		--s;
		k -= mink;
	}

	return s + 1;
}

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		scanf("%d %d %d", &R, &C, &K);

		printf("Case #%d: ", TT);

		if(R <= 2 || C <= 2 || K <= 4)
		{
			printf("%d\n", K);
		}
		else
		{
			int sol = 2 * (R + C - 2);

			VI v(12);
			v[0] = 0; v[1] = 0; v[2] = R - 1;
			v[3] = 0; v[4] = 0; v[5] = C - 1;
			v[6] = C - 1; v[7] = 0; v[8] = R - 1;
			v[9] = R - 1; v[10] = 0; v[11] = C - 1;
			int s = 2 * (R + C - 2);
			int k = R * C;

			sol = min <int> (sol, run(v, s, k));

			printf("%d\n", sol);
		}
	}

	return 0;
}
