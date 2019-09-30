#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#include <climits>
#include <fcntl.h>
#include <unistd.h>

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

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
}

struct rect
{
    int x1, y1, x2, y2;

    rect() {}
    rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

struct region
{
    vector<rect> rects;
};

static bool overlap(const rect &a, const rect &b)
{
    if (a.x1 > b.x2) return false;
    if (b.x1 > a.x2) return false;
    if (a.y1 > b.y2) return false;
    if (b.y1 > a.y2) return false;
    if (a.x2 == b.x1 && a.y2 == b.y1) return false;
    if (b.x2 == a.x1 && b.y2 == a.y1) return false;
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int R;
        cin >> R;
        vector<region> regions(R);
        for (int i = 0; i < R; i++)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            regions[i].rects.push_back(rect(x1, y1, x2 + 1, y2 + 1));
        }
        bool more = true;
        while (more)
        {
            more = false;
            for (size_t i = 0; i < regions.size(); i++)
                for (size_t j = i + 1; j < regions.size(); j++)
                {
                    for (size_t p = 0; p < regions[i].rects.size(); p++)
                        for (size_t q = 0; q < regions[j].rects.size(); q++)
                        {
                            if (overlap(regions[i].rects[p], regions[j].rects[q]))
                            {
                                regions[i].rects.insert(regions[i].rects.end(), RA(regions[j].rects));
                                more = true;
                                regions.erase(regions.begin() + j);
                                goto found;
                            }
                        }
                }
found:;
        }

        ll ans = 0;
        for (size_t i = 0; i < regions.size(); i++)
        {
            int low = INT_MAX;
            int maxx = INT_MIN;
            int maxy = INT_MIN;
            for (size_t j = 0; j < regions[i].rects.size(); j++)
            {
                const rect &r = regions[i].rects[j];
                low = min(low, r.x1 + r.y1);
                maxx = max(maxx, r.x2);
                maxy = max(maxy, r.y2);
            }
            ans = max(ans, (ll) maxx + maxy - low - 1);
        }

        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
