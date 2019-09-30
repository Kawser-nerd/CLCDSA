#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	int A, B, C, D, E, F, x = 1, y = 1;
	cin >> A >> B >> C >> D >> E >> F;
	for (int i = 0; i <= F / (100 * A); ++i)
	{
		int a = i * 100 * A;
		if (a > F) break;
		for (int j = 0; j <= F / (100 * B); ++j)
		{
			int b = j * 100 * B;
			if (a + b > F) break;
			for (int k = 0; k < F / C; ++k)
			{
				int c = k*C;
				if (a + b + c>F) break;
				for (int l = 0; l < F / D; ++l)
				{
					int d = l*D;
					if (a + b + c + d>F || (c + d)>(a + b) / 100 * E) break;
					int rz = c + d, rj = a + b;
					if (x*(rz + rj) <= rz*(x + y))
					{
						x = rz;
						y = rj;
					}
				}
			}
		}
	}
	cout << x + y << " " << x;
	return 0;
}