// Includes, declarations {{{
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <bitset>
using namespace std;
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,x) for(__typeof((x).begin())i=(x).begin();i!=(x).end();++i)
#define Dprintf(x...) fprintf(stderr, x);
typedef vector<int> VI;  typedef vector<VI> VVI;
typedef vector<string> VS;  typedef long long LL;
double PI = 2*acos(0.0);
// }}}
// String utils {{{
string readline() {
	string s; getline(cin, s);
	while (s.size() != 0 && isspace(s[s.size() - 1])) s.resize(s.size() - 1);
	return s;
}

string trim(const string &s) {
	size_t i, j, n = s.size();
	for (i = 0; i < n && isspace(s[i]); ++i) {}
	for (j = n; j > i + 1 && isspace(s[j-1]); --j) {}
	return s.substr(i, j - i);
}

vector<string> split(const string &s, const string &delims = " \t") {
	vector<string> res;
	for (size_t i = 0, j; i < s.size(); i = j + 1) {
		for (j = i; j < s.size() && delims.find(s[j]) == string::npos; ++j) {}
		if (j > i) res.push_back(s.substr(i, j - i));
	}
	return res;
}

LL atoi(string s) { return atoll(s.c_str()); }

template<typename T>
string tostr(const T &x) {
    stringstream os;
    os << x;
    return os.str();
}

string fmt(const char *f, ...) {
	va_list va; char *p = NULL; va_start(va, f);
	if (vasprintf(&p, f, va) < 0) return "";
	else { string s(p); free(p); return s; }
}

template<typename T> ostream &operator <<(ostream &o, const vector<T> &v) {
	o << "["; for (size_t i = 0; i < v.size(); i++) o << (i==0?"":", ") << v[i]; return o << "]";
}
// }}}

struct State {
    unsigned long long a[3];
    State() { a[0] = a[1] = a[2] = 0; }
    void set(int i) { a[i >> 6] |= 1ULL << (i & 63); }
    void reset(int i) { a[i >> 6] &= ~(1ULL << (i & 63)); }
    bool test(int i) { return (a[i >> 6] >> (i & 63)) & 1; }

    bool operator <(const State &s) const {
        for (int i = 0; i < 3; i++)
            if (a[i] != s.a[i]) return a[i] < s.a[i];
        return false;
    }

    bool zero() const { return a[0] == 0 && a[1] == 0 && a[2] == 0; }

    bool operator ==(const State &s) const {
        return s.a[0] == a[0] && s.a[1] == a[1] && s.a[2] == a[2];
    }
};

int DX[] = { 1, -1, 0, 0 };
int DY[] = { 0, 0, 1, -1 };
int adj[160][4];

int nrows, ncols, nrc;
char maze[20][20];
State goal;


bool connected(State s)
{
    int u;
    for (u = 0; u < nrc; u++) {
        if (s.test(u)) break;
    }

    vector<int> stk(1, u);
    while (!stk.empty()) {
        u = stk.back();
        stk.pop_back();
        s.reset(u);

        for (int d = 0; d < 4; d++) {
            int v = adj[u][d];
            if (v != -1 && s.test(v)) {
                s.reset(v);
                stk.push_back(v);
            }
        }
    }

    return s.zero();
}

bool valid(int y, int x)
{
    return 0 <= y && y < nrows && 0 <= x && x < ncols;
}


int main()
{
	int numCases = atoi(readline());
	for (int caseId = 1; caseId <= numCases; caseId++) {
		printf("Case #%d: ", caseId); fflush(stdout);

                goal = State();
                State init = State();

                scanf("%d %d", &nrows, &ncols);
                nrc = nrows * ncols;

                for (int i = 0; i < nrows; i++) {
                    for (int j = 0; j < ncols; j++) {
                        scanf(" %c", &maze[i][j]);
                        if (maze[i][j] == 'x' || maze[i][j] == 'w')
                            goal.set(i*ncols + j);
                        if (maze[i][j] == 'o' || maze[i][j] == 'w')
                            init.set(i*ncols + j);
                    }
                }

                for (int y0 = 0; y0 < nrows; y0++)
                for (int x0 = 0; x0 < ncols; x0++)
                for (int d = 0; d < 4; d++) {
                    int y1 = y0 + DY[d];
                    int x1 = x0 + DX[d];
                    int i = y0 * ncols + x0;
                    adj[i][d] = -1;
                    if (!valid(y1, x1)) continue;
                    if (maze[y1][x1] == '#') continue;
                    adj[i][d] = y1 * ncols + x1;
                }

                map<State, int> dist;
                queue<State> Q;

                Q.push(init);
                dist[init] = 0;

                bool found = false;

                while (!Q.empty()) {
                    State s = Q.front();
                    Q.pop();
                    int sDist = dist[s];
                    int sConn = connected(s);

                    if (s == goal) break;
                    if (found) break;

                    for (int i = 0; i < nrc; i++) {
                        if (!s.test(i)) continue;
                        for (int d = 0; d < 4; d++) {
                            if (adj[i][d] != -1 && adj[i][d^1] != -1 &&
                                !s.test(adj[i][d]) && !s.test(adj[i][d^1])) {
                                State t = s;
                                t.set(adj[i][d]);
                                t.reset(i);
                                if (dist.count(t) == 0) {
                                    int tConn = connected(t);
                                    if (sConn || tConn) {
                                        dist[t] = sDist + 1;
                                        Q.push(t);
                                        if (t == goal) found = true;
                                    }
                                }
                            }
                        }
                    }
                }
                printf("%d\n", dist.count(goal) ? dist[goal] : -1);
	}
}
