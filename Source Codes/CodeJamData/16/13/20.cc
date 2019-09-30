#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, T, prob=1;
	for (cin >> T; T--;) {
		cout << "Case #" << prob++ << ": ";

		cin >> N;
		vector<int> F(N+1);
		for (int i = 1; i <= N; i++) cin >> F[i];
		
		vector<vector<int> > ch(N+1);
		int ret = 0;
		for (int i = 1; i <= N; i++) {
			vector<int> n(N+1);
			int x = i, cur = 1;
			while (!n[x]) {
				n[x] = cur++;
				x = F[x];
			}
			ret = max(ret, cur - n[x]);
			if (cur - n[x] == 2) ch[x].push_back(cur-3);
		}

		int cur = 0;
		for (int i = 1; i <= N; i++) if (ch[i].size()) {
			sort(ch[i].begin(), ch[i].end());
			cur += 1+ch[i].back();
		}
		ret = max(ret, cur);

		cout << ret << endl;
	}
}
