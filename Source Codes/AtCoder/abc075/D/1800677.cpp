#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::stack;

using std::min;
using std::max;

struct point {
    int x;
    int y;
    point() : x(0), y(0) {}
    point(int x, int y) : x(x), y(y) {}
};

int count_point(const vector<point>& pp, int sx, int sy, int tx, int ty) {
    int cnt = 0;
    for (point p : pp) {
        if (sx <= p.x && p.x <= tx && sy <= p.y && p.y <= ty) {
            cnt += 1;
        }
    }
    return cnt;
}

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<point> pp(n);
    for (int i = 0; i < n; i++) {
        cin >> pp[i].x >> pp[i].y;
    }

    unsigned long ans = 1UL << 63;
    for (point p0 : pp) {
        for (point p1 : pp) {
            for (point p2 : pp) {
                for (point p3 : pp) {
                    if (p0.x != min(min(p0.x, p1.x), min(p2.x, p3.x))) {
                        continue;
                    }
                    if (p1.x != max(max(p0.x, p1.x), max(p2.x, p3.x))) {
                        continue;
                    }
                    if (p2.y != min(min(p0.y, p1.y), min(p2.y, p3.y))) {
                        continue;
                    }
                    if (p3.y != max(max(p0.y, p1.y), max(p2.y, p3.y))) {
                        continue;
                    }
                    if (!(count_point(pp, p0.x, p2.y, p1.x, p3.y) >= k)) {
                        continue;
                    }
                    unsigned long w = p1.x - p0.x;
                    unsigned long h = p3.y - p2.y;
                    ans = min(ans, w * h);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}