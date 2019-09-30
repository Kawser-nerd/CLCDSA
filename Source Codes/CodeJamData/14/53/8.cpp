// Rain Dreamer MODEL
// Create @ 23:21 06-14 2014
// Comment - 

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define RD(x) freopen (x, "r", stdin)
#define WT(x) freopen (x, "w", stdout)
#define clz(x) memset (x, 0, sizeof(x))
#define cln(x) memset (x, -1, sizeof(x))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int MAXN = 1000 + 10;

struct operation {
    bool enter;
    int id;
    
    void input() {
        char buf[4];
        scanf ("%s%d", buf, &id);
        enter = (buf[0] == 'E');
    }
    void print() {
        printf ("%c %d\n", enter? 'E' : 'L', id);
    }
};

operation op[MAXN];
vector<int> g[MAXN];
int match[MAXN];
bool vis[MAXN];
int n, goal_num;

void make_graph() {
    map<int, vector<int> > e, l;
    rep (i, n) {
        if (op[i].enter) {
            if (op[i].id) {
                e[op[i].id].push_back(i);
            }
        } else {
            if (op[i].id) {
                l[op[i].id].push_back(i);
            }
        }
        g[i].clear();
    }
    
    goal_num = 0;
    
    repeach (it, e) {
        //printf ("%d -> \n", it->first);
        int vsz = sz(it -> second);
        rep (i, vsz - 1) {
            goal_num ++;
            //printf ("%d, %d\n", it->second[i], it->second[i + 1]);
            repf (j, it->second[i] + 1, it->second[i + 1] - 1) {
                if (!op[j].enter && (op[j].id == 0 || op[j].id == op[it->second[i]].id)) {
                    g[it->second[i]].push_back(j);
                    //printf ("add %d %d\n", it->second[i], j);
                }
            }
        }
    }
    repeach (it, l) {
        //printf ("%d -> \n", it->first);
        int vsz = sz(it -> second);
        rep (i, vsz - 1) {
            goal_num ++;
            //printf ("%d, %d\n", it->second[i], it->second[i + 1]);
            repf (j, it->second[i], it->second[i + 1] - 1) {
                if (op[j].enter && (op[j].id == 0 || op[j].id == op[it->second[i]].id)) {
                    g[it->second[i]].push_back(j);
                    //printf ("add %d %d\n", it->second[i], j);
                }
            }
        }
    }
}

bool dfs(int x) {
    repeach (it, g[x]) {
        if (!vis[*it]) {
            vis[*it] = true;
            if (match[*it] == -1 || dfs(match[*it])) {
                match[*it] = x;
                return true;
            }
        }
    }
    return false;
}

int max_match() {
    memset (match, -1, sizeof(match));
    int ans = 0;
    rep (i, n) {
        cln (vis);
        ans += dfs(i);
    }
    return ans;
}

bool possible() {
    //return true;
    make_graph();
    //printf ("%d %d\n", max_match(), goal_num);
    return max_match() == goal_num;
}

bool can_m(int g, int c) {
    if (c == 0) return true;
    return g == 0 || g == c;
}

int get_ans() {
    //int num = 0;
    //rep (i, n) {
    //if (op[i].enter) {
    //num ++;
    //} else {
    //num = max(0, num - 1);
    //}
    //}
    //return num;

    map<int, vector<int> > e, l;
    rep (i, n) {
        if (op[i].enter) {
            e[op[i].id].push_back(i);
        } else {
            l[op[i].id].push_back(i);
        }
        g[i].clear();
    }

    goal_num = 0;

    repeach (it, e) {
        //printf ("%d -> \n", it->first);
        int vsz = sz(it -> second);

        goal_num += vsz;

        if (op[it->second[vsz - 1]].id == 0) {
            rep (i, vsz) {
                //printf ("%d, %d\n", it->second[i], it->second[i + 1]);
                repf (j, it->second[i] + 1, n - 1) {
                    if (!op[j].enter && can_m(op[j].id, op[it->second[i]].id)) {
                        g[it->second[i]].push_back(j);
                        //printf ("add %d %d\n", it->second[i], j);
                    }
                }
            }
            continue ;
        }

        rep (i, vsz - 1) {
            //printf ("%d, %d\n", it->second[i], it->second[i + 1]);
            repf (j, it->second[i] + 1, it->second[i + 1] - 1) {
                if (!op[j].enter && can_m(op[j].id, op[it->second[i]].id)) {
                    g[it->second[i]].push_back(j);
                    //printf ("add %d %d\n", it->second[i], j);
                }
            }
        }
        repf (j, it->second[vsz - 1] + 1, n - 1) {
            if (!op[j].enter && can_m(op[j].id, op[it->second[vsz - 1]].id)) {
                g[it->second[vsz - 1]].push_back(j);
                //printf ("add %d %d\n", it->second[vsz - 1], j);
            }
        }
    }
    return goal_num - max_match();
}

int main() {
    WT ("C2.out");
    repcase {
        scanf ("%d", &n);
        rep (i, n) {
            op[i].input();
        }
        printf ("Case #%d: ", Case++);
        //rep (i, n) {
            //op[i].print();
        //}
        if (possible()) {
            printf ("%d\n", get_ans());
        } else {
            puts ("CRIME TIME");
        }
    }
    return 0;
}

