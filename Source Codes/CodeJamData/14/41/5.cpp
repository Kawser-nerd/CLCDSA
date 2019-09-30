#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2e4;	

int N;
int X;
int A[MAXN];

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N >> X;
		for(int i = 0; i < N; i++) cin >> A[i];
		sort(A, A + N);
		int res = 0;
		for(int l = 0, r = N - 1; l <= r; ) {
			if(l == r) {
				res++;
				break;
			} else if(A[l] + A[r] <= X) {
				res++;
				l++, r--;
			} else {
				res++;
				r--;
			}
		}
		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}
