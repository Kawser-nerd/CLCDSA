#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 26;

int n, a[N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		static int id;
		printf("Case #%d: ", ++id);
		scanf("%d", &n);
		priority_queue<pair<int, char> > heap;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			sum += a[i];
			heap.push(make_pair(a[i], i));
		}
		n = sum;
		while (heap.size()) {
			char ch1 = heap.top().second;
			heap.pop();
			--a[ch1], --n;
			if (a[ch1]) {
				heap.push(make_pair(a[ch1], ch1));
			}
			if (heap.size() && heap.top().first * 2 > n) {
				char ch2 = heap.top().second;
				heap.pop();
				--a[ch2], --n;
				if (a[ch2]) {
					heap.push(make_pair(a[ch2], ch2));
				}
				printf("%c%c%c", 'A' + ch1, 'A' + ch2, n == 0 ? '\n' : ' ');
			} else {
				printf("%c%c", 'A' + ch1, n == 0 ? '\n' : ' ');
			}
		}
	}
	return 0;
}
