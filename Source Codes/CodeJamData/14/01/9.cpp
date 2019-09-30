#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;


int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		vector<int> cnt(16);
		for(int c = 0; c < 2; c++ ){
			int r; cin >> r; r--;
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					int v; cin >> v; v--;
					if(i == r) cnt[v] ++;
				}
			}
		}
		int res = 0;
		for(int i = 0; i < 16; i++) {
			if(cnt[i] == 2) {
				if(res == 0) res = i + 1;
				else res = -1;
			}
		}
		cout << "Case #" << t << ": ";
		if(res == 0) cout << "Volunteer cheated!";
		else if(res == -1) cout << "Bad magician!";
		else cout << res;
		cout << '\n';
	}
}
