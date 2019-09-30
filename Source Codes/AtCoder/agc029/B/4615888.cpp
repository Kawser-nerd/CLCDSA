#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
using namespace std;

long long N, A[200000], taken[200000];
long long sum, partner;
long long ans;
int main(void) {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	sort(A, A + N, greater<long long>());
	for (int i = 0; i < N; i++) {
		taken[i] = 0;
	}
	printf("\n");
	ans = 0;
	for (int i = 0; i < N; i++) {
		if (taken[i] == 1) {
			continue;
		}
		/*A[i]????????????*/
		sum = 1;
		while (sum <= A[i]) {
			sum *= 2;
		}
		partner = sum - A[i];
		/*taken[i] == 0??A[i]==partner??????i???????????*/
		int left = i+1;
		int right = N;
		while (right - left > 1) {
			int med = (left + right) / 2;
			if (A[med] < partner) {
				right = med;
			}
			else if (A[med] == partner && taken[med] == 1) {
				right = med;
			}
			else { 
				left = med;
			}
		}
		
		if (A[left] == partner && taken[left] == 0) {
			ans += 1;
			taken[i] = 1;
			taken[left] = 1;
		}
	}
	printf("%lld\n", ans);
}