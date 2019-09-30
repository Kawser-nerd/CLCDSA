#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

struct Node {
	vi children;
	char let;
	string sample(vector<Node>& nodes) const;
	int size = 1;
	void rec(vector<Node>& nodes) {
		trav(x, children) {
			nodes[x].rec(nodes);
			size += nodes[x].size;
		}
	}
};

string Node::sample(vector<Node>& nodes) const {
	string sa;
	int ind = 0;
	vector<string> outs;
	vi inds;
	trav(x, children) {
		sa += string(nodes[x].size, (char)(ind++));
		inds.push_back(0);
		outs.push_back(nodes[x].sample(nodes));
	}
	random_shuffle(all(sa));
	string out;
	out += let;
	rep(i,0,sz(sa)) {
		int x = sa[i];
		out += outs[x][inds[x]++];
	}
	return out;
}

void solve() {
	int N, M;
	cin >> N;
	vector<Node> nodes(N+1);
	rep(i,0,N) {
		int p;
		cin >> p;
		nodes[p].children.push_back(i+1);
	}
	nodes[0].let = 0;
	rep(i,0,N)
		cin >> nodes[i+1].let;
	Node& root = nodes[0];
	root.rec(nodes);
	cin >> M;
	vector<string> cool(M);
	rep(i,0,M)
		cin >> cool[i];
	int lim = 30000;
	vi counts(M);
	rep(i,0,lim) {
		string s = root.sample(nodes).substr(1);
		rep(j,0,M) if (s.find(cool[j]) != string::npos) counts[j]++;
	}
	rep(i,0,M) cout << setprecision(5) << fixed << ((double)counts[i] / lim) << ' ';
	cout << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
