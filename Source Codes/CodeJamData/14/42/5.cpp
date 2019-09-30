#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2000;

int N;
int A[MAXN];
int cost[MAXN];
int vals[MAXN];

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> A[i];
		}

		int res = 0;
		for(int i = 0; i < N; i++) {
			int numL = 0, numR = 0;
			for(int j = 0; j < N; j++) {
				if(A[j] > A[i]) {
					if(j < i) numL++;
					else numR++;
				}
			}
			res += min(numL, numR);
		}
		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}
