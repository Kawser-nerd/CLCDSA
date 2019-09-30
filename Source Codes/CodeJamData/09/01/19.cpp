#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_D = 5100, MAX_N = 510;

int L, D, N;
int d[MAX_D][16];
char buf[5000];

int main() {
	scanf("%d %d %d", &L, &D, &N);
	for (int i = 0; i < D; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < L; ++j)
			d[i][j] = 1 << (buf[j] - 'a');
	}
	for (int i = 0; i < N; ++i) {
		scanf("%s", buf);
		int len = strlen(buf), v[16];
		memset(v, 0, sizeof(v));
		for (int cnt = 0, p = 0; p < len; ++cnt) {
			if (buf[p] == '(') {
				++p;
				while (buf[p] != ')')
					v[cnt] |= 1 << (buf[p++] - 'a');
				++p;
			} else
				v[cnt] = 1 << (buf[p++] - 'a');
		}
		int ans = 0;
		for (int j = 0; j < D; ++j) {
			bool flag = true;
			for (int k = 0; k < L; ++k)
				if ((v[k] & d[j][k]) == 0) {
					flag = false;
					break;
				}
			if (flag)
				++ans;
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}
