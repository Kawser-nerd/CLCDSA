#include <cstdio>
#include <algorithm>

using namespace std;

char buf[600];
const char trgt[20] = "welcome to code jam";
int f[600][22];

int main()
{
	int T;
	scanf("%d", &T);
	gets(buf);
	for (int t = 0; t < T; ++t) {
		gets(buf);
		int len = strlen(buf);
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 0; i < len; ++i)
			for (int j = 0; j <= 19; ++j) {
				if (f[i][j] > 0)
					f[i + 1][j] = (f[i + 1][j] + f[i][j]) % 10000;
				if (j < 19 && buf[i] == trgt[j])
					f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % 10000;
			}
		printf("Case #%d: %04d\n", t + 1, f[len][19]);
	}
	return 0;
}

