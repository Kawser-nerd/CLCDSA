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

map<long long, long long> dpLarge;

const int LIM = 11400;
long long dp[LIM + 1];

struct Line
{
	long long low, high;
	long long value;

	bool operator < (long long x) const {
		return high < x;
	}
	bool operator > (long long x) const {
		return high > x;
	}
};

long long getLineHeight(const vector<Line> &lines, long long x)
{
	auto lineIndex = lower_bound(lines.begin(), lines.end(), x) - lines.begin();
	return lines[lineIndex].value;
}

long long getAns(long long n, long long a, long long b)
{
	if (n <= LIM) return dp[n];

	Line lastLine;
	lastLine.low = 1;
	lastLine.high = 1;
	lastLine.value = 0;

	vector<Line> lines;
	for (int i = 2; i <= LIM; i++) {
		if (lastLine.value != dp[i]) {
			lines.push_back(lastLine);
			lastLine.low = i;
			lastLine.high = i;
			lastLine.value = dp[i];
		}
		else {
			lastLine.high = i;
		}
	}

	for (;;)
	{
		long long curBegin = lines.back().high + 1;
		long long best = lines.back().value;
		long long bestX = -1;
		long long lowX = -1, highX = -1;

#pragma region binsearch
		{
			long long lower = 1, higher = curBegin - 1;
			while (lower <= higher) {
				long long mid = (lower + higher) / 2;
				long long forward = getLineHeight(lines, mid) + b-a;
				long long backward  = getLineHeight(lines, curBegin-mid);

				if (best > max(forward, backward)){
					best = max(forward, backward);
					bestX = mid;
				}
				if (forward > backward) {
					higher = mid - 1;
				}
				else {
					lower = mid + 1;
				}
			}

			if (bestX == -1) {
				lowX = 1, highX = 1;
			}
			else
			{
				lowX = bestX, highX = bestX;
			
				lower = 2, higher = bestX-1;
				while (lower <= higher) {
					long long mid = (lower + higher) / 2;
					long long forward = getLineHeight(lines, mid) + b - a;
					long long backward = getLineHeight(lines, curBegin - mid);
					if (best == max(forward, backward)) {
						lowX = mid;
						higher = mid - 1;
					}
					else {
						lower = mid + 1;
					}
				}
				lower = bestX + 1, higher = curBegin-1;
				while (lower <= higher) {
					long long mid = (lower + higher) / 2;
					long long forward = getLineHeight(lines, mid) + b - a;
					long long backward = getLineHeight(lines, curBegin - mid);
					if (best == max(forward, backward)) {
						highX = mid;
						lower = mid + 1;
					}
					else {
						higher = mid - 1;
					}
				}
			}
		}
#pragma endregion binsearch

		lastLine.low = curBegin;
		lastLine.high = curBegin + (highX - lowX)/2;
		lastLine.value = best + a;

		if (n <= lastLine.high) {
			return lastLine.value;
		}
		lines.push_back(lastLine);
	}
	return -1;
}

int main()
{
	int TT;
	scanf("%d", &TT);
	for (int testcase = 1; testcase <= TT; testcase ++)
	{
		fprintf(stderr, "Processing case %d\n", testcase);
		long long n, a, b;
		scanf("%lld%lld%lld", &n, &a, &b);
		dpLarge.clear();

		for (int i = 1; i <= LIM; i++) {
			if (i == 1) {
				dp[i] = 0;
				continue;
			}
			long long low = 2, high = i/2;
			long long res = dp[i - 1] + a;
			while (low <= high) {
				long long mid = (low + high) / 2;
				res = min(res, max(dp[mid]+b, dp[i-mid]+a));
				if (dp[mid] + b > dp[i - mid] + a) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			dp[i] = res;
		}

		long long answer = getAns(n,a,b);
		printf("Case #%d: %lld\n", testcase, answer);
		fprintf(stderr, "Finished case %d\n", testcase);
	}
	return 0;
}