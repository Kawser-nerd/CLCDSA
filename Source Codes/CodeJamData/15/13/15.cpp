#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Point {
    int x, y;

    Point (int x = 0, int y = 0) : x(x), y(y) {}

    void in() {
        scanf("%d%d", &x, &y);
    }

    int dim() const {
        return y > 0 || y == 0 && x >= 0;
    }
};

Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

long long det (const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

bool operator < (const Point &a, const Point &b) {
    if (a.dim() != b.dim()) {
        return a.dim() > b.dim();
    } else {
        return det(a, b) < 0;
    }
}

int n;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<Point> p(n);
        for (int i = 0; i < n; ++i) {
            p[i].in();
        }
        static int id = 0;
        printf("Case #%d:\n", ++id);
        for (int i = 0; i < n; ++i) {
            vector<pair<Point, int> > c;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    c.push_back(make_pair(p[j] - p[i], 1));
                    c.push_back(make_pair(p[i] - p[j], -1));
                }
            }
            sort(c.begin(), c.end()); 
            int m = c.size();
            for (int j = 0; j < m; ++j) {
                c.push_back(c[j]);
            }
            int left = 0, right = 0;
            for (int j = 0; j < m; ++j) {
                if (c[j].second < 0) {
                    continue;
                }
                if (det(c[0].first, c[j].first) == 0) {
                    if (c[0].first.dim() == c[j].first.dim()) {
                        ++left;
                    } else {
                        ++right;
                    }
                } else {
                    if (det(c[0].first, c[j].first) < 0) {
                        ++left;
                    } else {
                        ++right;
                    }
                }
            }
            /*
            cout << i << endl;
            for (int j = 0; j < m; ++j) {
                cout << c[j].first.x << ' ' << c[j].first.y << ' ' << c[j].second << endl;
            }
            //cout << left << ' ' << right << endl;
            */
            int ans = n - 1;
            for (int j = 0; j < m; ++j) {
                int k = j;
                int dl = 0, dr = 0;
                while (k < m && det(c[j].first, c[k].first) == 0) {
                    if (c[k].second == 1) {
                        ++dl;
                    } else {
                        ++dr;
                    }
                    ++k;
                }
                left -= dl;
                right -= dr;
                //cout << "HAHA" << ' ' << left << ' ' << right << endl;
                ans = min(ans, min(left, right));
                right += dl;
                left += dr;
                //cout << left << ' ' << right << endl;
                j = k - 1;
            }
            if (ans < 0) {
                ans = 0;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
