#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1440;
const int inf = 0x3f3f3f3f;

int F[1450][1450][2];
int A[1450];

int main()
{
	int T, M1, M2;
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &T);
	for (int _T = 1; _T <= T; _T++)
	{
		scanf("%d%d", &M1, &M2);
		memset(A, 0xff, sizeof(A));
		for (int i = 0; i < M1; i++)
		{
			int L, R;
			scanf("%d%d", &L, &R);
			for (int j = L; j < R; j++) A[j] = 0;
		}
		for (int i = 0; i < M2; i++)
		{
			int L, R;
			scanf("%d%d", &L, &R);
			for (int j = L; j < R; j++) A[j] = 1;
		}
		int ans = inf;
		if (A[0] != 1)
		{
			memset(F, 0x3f, sizeof(F));
			F[1][0][0] = 0;
			for (int i = 1; i <= N - 1; i++)
				for (int j = 0; j <= i; j++)
				{
					int k = i - j;
					for (int l0 = 0; l0 <= 1; l0++)
						if (F[j][k][l0] < inf)
						{
							if (A[i] != 1) F[j + 1][k][0] = min(F[j + 1][k][0], F[j][k][l0] + l0);
							if (A[i] != 0) F[j][k + 1][1] = min(F[j][k + 1][1], F[j][k][l0] + (!l0));
						}
				}
			ans = min(ans, min(F[N / 2][N / 2][0], F[N / 2][N / 2][1] + 1));
		}
		if (A[0] != 0)
		{
			memset(F, 0x3f, sizeof(F));
			F[0][1][1] = 0;
			for (int i = 1; i <= N - 1; i++)
				for (int j = 0; j <= i; j++)
				{
					int k = i - j;
					for (int l0 = 0; l0 <= 1; l0++)
						if (F[j][k][l0] < inf)
						{
							if (A[i] != 1) F[j + 1][k][0] = min(F[j + 1][k][0], F[j][k][l0] + l0);
							if (A[i] != 0) F[j][k + 1][1] = min(F[j][k + 1][1], F[j][k][l0] + (!l0));
						}
				}
			ans = min(ans, min(F[N / 2][N / 2][0] + 1, F[N / 2][N / 2][1]));
		}
		printf("Case #%d: %d\n", _T, ans);
	}
	return 0;
}
