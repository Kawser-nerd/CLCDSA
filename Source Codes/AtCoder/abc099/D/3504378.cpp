#include <iostream>
#include <vector>
#include <cmath>
#include <limits>


using namespace std;
typedef long long int lli;

int main() {
	int N, C;

    cin >> N >> C;

	vector<vector<lli>> D;
	for(int i=0; i<C; i++) {
		vector<lli> di;
		for(int j=0; j<C; j++) {
			lli dij;
			cin >> dij;
			di.push_back(dij);
		}
		D.push_back(di);
	}

	vector<vector<int>> c_dist;
	for(int i=0; i<3; i++) {
		vector<int> ccc(C, 0);
		c_dist.push_back(ccc);
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			int cij;
			cin >> cij;
			c_dist[(i+1+j+1)%3][cij-1]++;
		}
	}

	lli ans = numeric_limits<lli>::max();
	for(int c1=0; c1<C; c1++) {
		for(int c2=0; c2<C; c2++) {
			for(int c3=0; c3<C; c3++) {
				if(c1 == c2 || c2 == c3 || c3 == c1) {
					continue;
				}
				lli incomp = 0;
				for(int cc=0; cc<C; cc++) {
					incomp += c_dist[0][cc] * D[cc][c1];
					incomp += c_dist[1][cc] * D[cc][c2];
					incomp += c_dist[2][cc] * D[cc][c3];
				}
				ans = min(incomp, ans);
			}
		}
	}
	cout << ans << endl;
}