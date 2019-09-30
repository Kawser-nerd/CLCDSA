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
int N, X, Y;

double a[2000][2000];

double get(int left, int slot, int Y) {
	if(slot > 1500) while(1);
	memset(a, 0, sizeof(a));
	a[0][0] = 1.0;
	for(int x=0; x<=slot; x++) {
		for(int y=0; y<=slot; y++) {
			if(x<slot && y<slot) {
				a[x+1][y] += 0.5 * a[x][y];
				a[x][y+1] += 0.5 * a[x][y];
			} else if(x<slot) {
				a[x+1][y] += a[x][y];
			} else if(y<slot){
				a[x][y+1] += a[x][y];
			}
		}
	}
	double res = 0;
	for(int x=0; x<=slot; x++) {
		int y = left - x;
		if(y >= Y && y <= slot) {
			res += a[x][y];
		}
	}
	return res;
}

int main() {
	
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d%d", &N, &X, &Y);
		
		int a = 1, total = 1;
		for(a=1; ; a+=2) {
			total = a * (a+1) / 2;
			if(N < total) break;
		}

		a-=2;
		total = a * (a+1) / 2;
		
		double answer = 0.0;
		int lvl = abs(X) + Y;

		if(lvl < a) {
			answer = 1.0;
		} else if(lvl == a+1) {
			int left = N - total;
			int slot = a+1;

			if(left == slot + slot + 1) {
				answer = 1.0;
			} else if(Y == slot) {
				answer = 0.0;
			} else {
				answer = get(left, slot, Y+1);
			}
		} else {
			answer = 0.0;
		}

		printf("Case #%d: %lf\n", test, answer);
	}
	return 0;
}
