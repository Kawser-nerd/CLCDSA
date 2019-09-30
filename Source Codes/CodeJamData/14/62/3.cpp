#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <numeric>

#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

int n;
int dat[1<<12];

int rec(vector<int> state){
	int ret = 0;
	if (is_sorted(dat, dat + (1 << n))) ret++;
	for (int i = 0; i < n; i++) {
		if (state[i]) continue;
		for (int j = 0; j < (1 << n); j += (1 << i)) {
			for (int jj = j; jj < (1 << n); jj += (1 << i)) {
				if (jj == j) continue;
				for (int k = 0; k < (1 << i); k++) {
					swap(dat[j+k], dat[jj+k]);
				}
				state[i] = 1;
				ret += rec(state);
				state[i] = 0;
				for (int k = 0; k < (1 << i); k++) {
					swap(dat[j + k], dat[jj + k]);
				}
			}
		}
	}
	return ret;
}

int main()
{
	int TT;
	scanf("%d", &TT);
	for (int testcase = 1; testcase <= TT; testcase ++)
	{
		scanf("%d", &n);
		for (int i = 0; i < (1 << n); i++){
			scanf("%d", &dat[i]);
		}
		vector<int> used(n);
		int res = rec(used);
		printf("Case #%d: %d\n", testcase, res);
	}
	return 0;
}