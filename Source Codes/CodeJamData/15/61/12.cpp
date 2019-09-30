#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long i64;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)) % MOD)
#define DBG(...) (fprintf(stderr, "[line %d]: ", __LINE__), fprintf(stderr, __VA_ARGS__))

char in[1010101];
int L;

int dpL[182][1010101], dpR[182][1010101];

int main()
{
	int n_testcase;
	scanf("%d", &n_testcase);
	
	for (int testcase_id = 0; testcase_id++ < n_testcase; ) {
		// input and solve the problem
		scanf("%s", in); L = strlen(in);
		
		for (int i = 0; i <= L; ++i) {
			for (int j = 0; j <= 180; ++j) {
				dpL[j][i] = i;
				dpR[j][i] = i;
			}
		}
		int ret = 11111;
		for (int j = 0; j <= 180; ++j) {
			for (int i = 0; i < L; ++i) {
				int v = in[i] - '0';
				if (v <= j) {
					dpL[j][i] = max(dpL[j][i], i + 1);
					dpR[j][i + 1] = min(dpR[j][i + 1], i);
					
					dpL[j][dpR[j - v][i]] = max(dpL[j][dpR[j - v][i]], dpL[j - v][i + 1]);
					dpR[j][dpL[j - v][i + 1]] = min(dpR[j][dpL[j - v][i + 1]], dpR[j - v][i]);
				}
			}
			
			for (int i = 0; i < L; ++i) dpL[j][i + 1] = max(dpL[j][i + 1], dpL[j][i]);
			for (int i = L; i >= 1; --i) dpR[j][i - 1] = min(dpR[j][i - 1], dpR[j][i]);
			
			if (dpL[j][0] == L) {
				ret = j;
				break;
			}
		}

		printf("Case #%d: %d\n", testcase_id, ret);
		// print answer here
	}
	return 0;
}

