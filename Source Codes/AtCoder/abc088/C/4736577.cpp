#include <iostream>
using namespace std;

typedef long long ll;
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define rerepi(i, a, b) for(int i = int(a)-1; i >= b; --i)
#define rerep(i, n) rerepi(i, n, 0)
#define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

// ?????????
ll mtrix[4][4], tmp1, tmp2;
bool a[4], b[4];

int main() {
	repi(i, 1, 4) {
		repi(j, 1, 4) {
			cin >> mtrix[i][j];
		}
	}
	
	repi(a, 1, 4) {
		if (a == 1) {
			tmp1 = mtrix[a][1] - mtrix[a][2];
			tmp2 = mtrix[a][2] - mtrix[a][3];
		} else {
			if(!(mtrix[a][1] - mtrix[a][2] == tmp1 && mtrix[a][2] - mtrix[a][3] == tmp2)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	
	repi(b, 1, 4) {
		if (b == 1) {
			tmp1 = mtrix[1][b] - mtrix[2][b];
			tmp2 = mtrix[2][b] - mtrix[3][b];
		} else {
			if(!(mtrix[1][b] - mtrix[2][b] == tmp1 && mtrix[2][b] - mtrix[3][b] == tmp2)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}