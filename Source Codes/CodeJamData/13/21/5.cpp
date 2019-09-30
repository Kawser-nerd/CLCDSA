#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<sstream>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 105;

int ntest;
int A, N;
int x[maxn];

int main() {
	
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d", &A, &N);
		for(int i=0; i<N; i++) {
			scanf("%d", &x[i]);
		}
		sort(x, x+N);
		int answer = N;
		int now = 0;
		for(int i=0; i<N; i++) {
			if((now + N-i) < answer) {
				answer = now + N - i;
			}
			while(A <= x[i] && now <= answer) {
				A = A + (A-1);
				now++;
			}
			if(now > answer) break;
			A += x[i];
		}
		if(now < answer) {
			answer = now;
		}

		printf("Case #%d: %d\n", test, answer);
	}
	return 0;
}
