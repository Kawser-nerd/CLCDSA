#include <iostream>
#include <vector>
using namespace std;
struct edge { int to, num; };

vector<edge>g[50];
int n, m, ans = 0;
bool used[50];

void search(int a, int num) {
	used[a] = true;
	//cout << "????" << a << "???" << endl;
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i].num != num && !used[g[a][i].to]) {
			//cout << "g[a][i].num" << g[a][i].num << " num:" << num  << endl;
			search(g[a][i].to, num);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(edge{ b - 1, i });
		g[b - 1].push_back(edge{ a - 1, i });
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)used[j] = false;

		//cout << i << "??" << endl;
		search(0, i);

		bool flag = false;
		for (int j = 0; j < n; j++)if (!used[j])flag = true;

		if (flag) {
			//cout << "????" << endl;
			ans++;
		}
		else {
			//cout << "????" << endl;
		}
	}

	cout << ans << endl;
}