#include <cstdio>
#include <algorithm>

using namespace std;

char dat[2000];

int main() {
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++) {
		int smax;
		scanf("%d",&smax);
		scanf("%s",dat);
		int cnt = 0;
		int ans = 0;
		for (int i = 0; i <= smax; i++) {
			if (cnt < i) {
				ans++;
				cnt++;
			}
			cnt += dat[i]-'0';
		}
		printf("Case #%d: %d\n", testcase, ans);
	}
}