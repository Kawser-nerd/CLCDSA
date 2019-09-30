#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

int dat[1000003];
long long sum[1000003];

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		int n,p,q,r,s;
		scanf("%d%d%d%d%d",&n,&p,&q,&r,&s);
		for(int i = 0; i < n;i ++) {
			dat[i] = ((i*(long long)p+q)%r+s);
			sum[i+1] = sum[i] + dat[i];
		}
		long long maxAns = 0;
		for(int i = 0; i < n; i++) {
			long long firstPart = sum[i];
			int low = i, high = n-1;
			int minLarger = n-1;
			while(low <= high) {
				int mid = (low+high) / 2;
				long long secondPart = sum[mid+1] - firstPart;
				long long thirdPart = sum[n] - sum[mid+1];
				if (secondPart < thirdPart) {
					low = mid + 1;
				} else {
					high = mid - 1;
					minLarger = mid;
				}
			}
			for(int mid = minLarger - 2; mid <= minLarger + 2; mid++) {
				if (!(i <= mid && mid < n)) continue;
				long long secondPart = sum[mid+1] - firstPart;
				long long thirdPart = sum[n] - sum[mid+1];
				if (firstPart >= secondPart && firstPart >= thirdPart) {
					maxAns = max(maxAns, secondPart + thirdPart);
				} else if(secondPart >= thirdPart) {
					maxAns = max(maxAns, (firstPart + thirdPart));
				} else {
					maxAns = max(maxAns, (firstPart + secondPart));
				}
			}
		}
		printf("Case #%d: %.12f\n", testcase, (maxAns) / (double)(sum[n]));
	}
	return 0;
}
