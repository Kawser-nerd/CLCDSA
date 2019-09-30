#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct NFA;

struct Re {
	enum { CONCAT, DIG, STAR, OR };
	int type;
	char value;
	Re *a, *b;

	static Re* nor(Re* a, Re* b) {
		Re* ret = new Re;
		ret->type = OR;
		ret->a = a;
		ret->b = b;
		return ret;
	}

	static Re* concat(Re* a, Re* b) {
		Re* ret = new Re;
		ret->type = CONCAT;
		ret->a = a;
		ret->b = b;
		return ret;
	}

	static Re* star(Re* a) {
		if (a->type == STAR) return a;
		Re* ret = new Re;
		ret->type = STAR;
		ret->a = a;
		return ret;
	}

	static Re* dig(char c) {
		Re* ret = new Re;
		ret->type = DIG;
		ret->value = c;
		return ret;
	}

	void build(NFA& nfa, int from, int to);
};

Re* parse2(string s);

Re* parseOr(string s) {
	int bal = 0;
	rep(i,0,sz(s)) {
		char c = s[i];
		if (c == '(') bal++;
		if (c == ')') bal--;
		if (c == '|' && !bal) {
			return Re::nor(parse2(s.substr(0, i)), parseOr(s.substr(i+1)));
		}
	}
	assert(!bal);
	return parse2(s);
}

Re* parse2(string s) {
	int i = 0;
	Re* old = 0;
	while (i < sz(s)) {
		char c = s[i];
		Re* r;
		if (c == '(') {
			int bal = 0;
			int j = i+1;
			while (j < sz(s)) {
				char c = s[j];
				if (c == '(') bal++;
				if (c == ')') bal--;
				if (bal == -1) break;
				j++;
			}
			r = parseOr(s.substr(i+1, j-i-1));
			i = j;
		}
		else {
			assert('0' <= c && c <= '9');
			r = Re::dig(c);
		}
		i++;

		while (i < sz(s) && s[i] == '*') {
			r = Re::star(r);
			i++;
		}

		if (old)
			old = Re::concat(old, r);
		else
			old = r;
	}
	return old;
}

struct NFA {
	struct Node {
		vector<pair<int,char>> out;
		vector<int> eps;
	};
	vector<Node> nodes;

	int addNode() {
		Node n;
		int i = sz(nodes);
		nodes.push_back(n);
		return i;
	}

	void addTransition(int a, int b, char c) {
		nodes[a].out.emplace_back(b, c);
	}

	void addEpsTransition(int a, int b) {
		nodes[a].eps.push_back(b);
	}
};

void Re::build(NFA& nfa, int from, int to) {
	if (type == STAR) {
		int mid = nfa.addNode();
		nfa.addEpsTransition(from, mid);
		nfa.addEpsTransition(mid, to);
		a->build(nfa, mid, mid);
	}
	else if (type == DIG) {
		nfa.addTransition(from, to, value);
	}
	else if (type == CONCAT) {
		int mid = nfa.addNode();
		a->build(nfa, from, mid);
		b->build(nfa, mid, to);
	}
	else {
		assert(type == OR);
		a->build(nfa, from, to);
		b->build(nfa, from, to);
	}
}

ll sol2(string str, int wildcards, Re* re) {
	NFA nfa;
	int start = nfa.addNode();
	int end = nfa.addNode();
	re->build(nfa, start, end);
	int N = sz(nfa.nodes);

	vector<bool> accepting(N);
	rep(i,0,N) {
		vi seen(N);
		seen[i] = 1;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int x = q.front();
			if (x == end) accepting[i] = true;
			if (x != i) {
				trav(pa, nfa.nodes[x].out) {
					nfa.nodes[i].out.push_back(pa);
				}
			}
			q.pop();
			trav(y, nfa.nodes[x].eps) {
				if (seen[y]) continue;
				seen[y] = 1;
				q.push(y);
			}
		}
	}

	/*
	cout << start << ' ' << end << endl;
	rep(i,0,N) {
		cout << i << ":";
		trav(pa, nfa.nodes[i].out) cout << " (" << pa.first << ", " << pa.second << ")";
		cout << " +";
		trav(x, nfa.nodes[i].eps) cout << ' ' << x << endl;
		cout << endl;
	}
	abort();
	*/

	auto next = [&](char c, const vector<bool>& at) -> vector<bool> {
		vector<bool> at2(N);
		rep(i,0,N) if (at[i]) {
			trav(pa, nfa.nodes[i].out) {
				if (pa.second == c)
					at2[pa.first] = 1;
			}
		}
		return at2;
	};

	vector<bool> at(N);
	at[start] = 1;
	trav(c, str) {
		at = next(c, at);
	}

	map<vector<bool>, ll> reachable;
	reachable[at] = 1;

	rep(i,0,wildcards) {
		map<vector<bool>, ll> reachable2;
		trav(v, reachable) {
			rep(d,0,10) {
				char c = char(d + '0');
				vector<bool> n2 = next(c, v.first);
				reachable2[n2] += v.second;
			}
		}
		reachable.swap(reachable2);
	}

	ll res = 0;
	trav(v, reachable) {
		bool good = false;
		vector<bool> at = v.first;
		rep(i,0,N) {
			if (!!at[i] && accepting[i]) good = 1;
		}
		if (good) res += v.second;
	}

	return res;
}

ll sol(ll lim, Re* re) {
	assert(lim);
	ll res = 0;

	ostringstream oss;
	oss << lim;
	string s = oss.str();

	rep(i,0,sz(s)) {
		// fix chars 0 .. i, inclusive
		int c = s[i] - '0';
		rep(d,0,c) {
			if (!d && i == 0) continue;
			res += sol2(s.substr(0, i) + (char)('0' + d), sz(s) - i - 1, re);
		}
	}

	// truncate to various lengths
	rep(l,1,sz(s)) {
		rep(d,1,10) {
			res += sol2(string(1, (char)('0' + d)), l - 1, re);
		}
	}

	return res;
}

/*
ll sol(ll lim, Re* re) {
	ll res = 0;
	rep(i,1,lim) {
		ostringstream oss;
		oss << i;
		string s = oss.str();
		res += sol2(s, 0, re);
	}
	return res;
}
*/

void solve() {
	ll a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	Re* re = parseOr(s);
	cout << sol(b+1, re) - sol(a, re) << endl;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
