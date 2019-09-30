#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR2(i, a, b) for (int i = (a); i > (b); --i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=last_bit(n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node
{
	map<string, Node *> next;
};

void del(Node * n)
{
	for (map<string, Node*>::iterator iter = n->next.begin(); iter != n->next.end(); ++iter)
		del(iter->second);
	delete n;
}

vector<string> parse(string path)
{
	int be = 1, en;
	vector<string> res;
	while (be < path.size())
	{
		en = be;
		while (en < path.size() && path[en] != '/') ++en;
		res.push_back(path.substr(be, en-be));
		be = en+1;
	}
	return res;
}

void Solve(int tc)
{
	int N, M;
	cin >> N >> M;
	Node * root = new Node();

	FOR(i, 0, N)
	{
		string in;
		cin >> in;
		vector<string> path = parse(in);

		Node * n = root;
		FOR(j, 0, path.size())
		{
			map<string, Node*>::iterator iter = n->next.find(path[j]);
			if (iter == n->next.end())
			{
				n->next[path[j]] = new Node();
			}
			n = n->next[path[j]];
		}
	}

	int res = 0;
	FOR(i, 0, M)
	{
		string in;
		cin >> in;
		vector<string> path = parse(in);

		Node * n = root;
		FOR(j, 0, path.size())
		{
			map<string, Node*>::iterator iter = n->next.find(path[j]);
			if (iter == n->next.end())
			{
				n->next[path[j]] = new Node();
				++res;
			}
			n = n->next[path[j]];
		}
	}
	del(root);

	cout << "Case #" << tc << ": " << res << endl;
}

int main()
{
	int T;
	cin >> T;
	FOR(step, 0, T) Solve(step+1);

	return 0;
}