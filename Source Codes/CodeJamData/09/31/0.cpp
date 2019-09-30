#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

char input[100];
int value[256], vused;

int main() {
	int T;
	scanf("%d ",&T);
	for (int test=1;test<=T;test++) {
		scanf("%s ",input);
		for (char c = 'a'; c <= 'z'; c++) {value[c] = 0;}
		for (char c = '0'; c <= '9'; c++) {value[c] = 0;}
		vused = 0;
		
		for (int i = 0; i < strlen(input); i++) {
			if (value[input[i]] == 0) {
				value[input[i]] = ++vused;
			}
		}
		if (vused <= 1) {vused = 2;}
		long long ans = 0;
		for (int i = 0; i < strlen(input); i++) {
			long long tmp = value[input[i]];
			if (tmp == 1) {
			} else if (tmp == 2) {
				tmp = 0;
			} else {
				tmp--;
			}
			ans = ans*vused + tmp;
		}
		printf("Case #%d: %lld\n",test,ans);
	}
}