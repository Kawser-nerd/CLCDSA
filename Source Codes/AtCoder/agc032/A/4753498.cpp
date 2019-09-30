#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define rerepi(i, a, b) for(int i = int(a)-1; i >= b; --i)
#define rerep(i, n) rerepi(i, n, 0)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline void remove(std::vector<T>& vector, unsigned int index) { vector.erase(vector.begin() + index); }

const long long INF = 1LL << 60;

// ?????????
ll N, mark;
vector<ll> B, ans;

int main() {
	// ?????
	cin.tie(0);
	ios::sync_with_stdio(false);
	// ????

	cin >> N;
	rep(i, N) {
		ll tmp;
		cin >> tmp;
		B.push_back(tmp);
	}

	while (!B.empty()) {
		mark = -1;
		rep(i, B.size()) {
			if (B[i] == i + 1 && mark < i + 1) {
				mark = i + 1;
			}
		}
		if (mark == -1) {
			cout << -1 << endl;
			return 0;
		}
		else {
			remove(B, mark-1);
			ans.push_back(mark);
		}
	}

	rerep(i, ans.size()) {
		cout << ans[i] << endl;
	}

	return 0;
}