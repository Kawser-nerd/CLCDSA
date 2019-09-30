#include <iostream>
#include <cassert>

using namespace std;

inline bool same(int a, int b, int c, int d)
{
	return a == c && b == d;
}

int main()
{
	int kases, kase = 0;
	for (cin >> kases; kases; kases--)
	{
		int n;
		long long A, B, C, D, x0, y0, M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;

		int cnt[3][3] = {{0}};
		while (n--)
		{
			cnt[x0 % 3][y0 % 3]++;
			long long x1 = (A*x0 + B) % M;
			long long y1 = (C*y0 + D) % M;
			x0 = x1;
			y0 = y1;
		}

		long long res = 0;
		for (int i1 = 0; i1 < 3; i1++)
			for (int j1 = 0; j1 < 3; j1++)
				for (int i2 = 0; i2 < 3; i2++)
					for (int j2 = 0; j2 < 3; j2++)
						for (int i3 = 0; i3 < 3; i3++)
							for (int j3 = 0; j3 < 3; j3++)
								if ((i1 + i2 + i3) % 3 == 0 && (j1 + j2 + j3) % 3 == 0)
								{
									const long long o1 = cnt[i1][j1];
									const long long o2 = cnt[i2][j2];
									const long long o3 = cnt[i3][j3];
									if (same(i1,j1,i2,j2) && same(i1,j1,i3,j3))
										res += o1 * (o1-1) * (o1-2);
									else if (same(i1,j1,i2,j2))
										res += o1 * (o1-1) * o3;
									else if (same(i1,j1,i3,j3))
										res += o1 * (o1-1) * o2;
									else if (same(i2,j2,i3,j3))
										res += o1 * o2 * (o2-1);
									else
										res += o1 * o2 * o3;
								}
		assert((res % 6) == 0);
		res /= 6;
		cout << "Case #" << ++kase << ": " << res << endl;
	}
	return 0;
}
