#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

struct node
{
    int cost[2];
    bool is_and;
    bool change;
};

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int M, V;
        cin >> M >> V;
        vector<node> nodes(M + 1);
        for (int i = 1; i <= M / 2; i++)
        {
            int G, C;
            cin >> G >> C;
            nodes[i].is_and = G;
            nodes[i].change = C;
            nodes[i].cost[0] = nodes[i].cost[1] = INT_MAX / 4;
        }
        for (int i = M / 2 + 1; i <= M; i++)
        {
            int V;
            cin >> V;
            nodes[i].cost[V] = 0;
            nodes[i].cost[1 - V] = INT_MAX / 4;
        }

        for (int i = M / 2; i > 0; i--)
        {
            int comb[4] = {0, !nodes[i].is_and, !nodes[i].is_and, 1};
            nodes[i].cost[comb[0]] = min(nodes[i].cost[comb[0]], nodes[2 * i].cost[0] + nodes[2 * i + 1].cost[0]);
            nodes[i].cost[comb[1]] = min(nodes[i].cost[comb[1]], nodes[2 * i].cost[0] + nodes[2 * i + 1].cost[1]);
            nodes[i].cost[comb[2]] = min(nodes[i].cost[comb[2]], nodes[2 * i].cost[1] + nodes[2 * i + 1].cost[0]);
            nodes[i].cost[comb[3]] = min(nodes[i].cost[comb[3]], nodes[2 * i].cost[1] + nodes[2 * i + 1].cost[1]);
            if (nodes[i].change)
            {
                comb[1] = !comb[1];
                comb[2] = !comb[2];
                nodes[i].cost[comb[1]] = min(nodes[i].cost[comb[1]], nodes[2 * i].cost[0] + nodes[2 * i + 1].cost[1] + 1);
                nodes[i].cost[comb[2]] = min(nodes[i].cost[comb[2]], nodes[2 * i].cost[1] + nodes[2 * i + 1].cost[0] + 1);
            }
        }
        printf("Case #%d: ", cas + 1);
        if (nodes[1].cost[V] == INT_MAX / 4)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", nodes[1].cost[V]);
    }
    return 0;
}
