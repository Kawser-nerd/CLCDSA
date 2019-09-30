#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long LL;

static const int MAXN = 100000 + 5;
static const LL MAXC = 100000000 + 5;

int r, c;

struct Point{
    int x;
    int y;
    int id;
    Point(int _x, int _y, int _id) {
        x = _x;
        y = _y;
        id = _id;

    }
    LL val() {
        LL base = MAXC * 10;
        if (x == 0 && y == 0) return 0;
        if (x == 0 && y == c) return 2*base;
        if (x == r && y == c) return 4*base;
        if (x == r && y == 0) return 6*base;
        if (x == 0) return base + y;
        if (y == c) return 3*base + x;
        if (x == r) return 5*base - y;
        if (y == 0) return 7*base - x;

    }
};

bool bound(int x, int y) {
    if (x == 0 || x == r) return true;
    if (y == 0 || y == c) return true;
    return false;
}

static bool cmp(Point p1, Point p2) {
    LL v1 = p1.val();
    LL v2 = p2.val();
    return v1 < v2;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, x1, y1, x2, y2;
    scanf("%d%d%d", &r, &c, &n);
    vector<Point> points;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (bound(x1 ,y1) && bound(x2, y2)) {
            points.push_back(Point(x1,y1,i));
            points.push_back(Point(x2,y2,i));
        }
    }
    sort(points.begin(), points.end(), cmp);
    stack<int> st;
    for (Point p : points) {
        if (st.size() == 0) {
            st.push(p.id);
        }
        else {
            if (st.top() == p.id) {
                st.pop();
            }
            else { // st.top() != p.id
                st.push(p.id);
            }
        }
    }
    if (st.size() == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }


    return 0;
} ./Main.cpp:34:5: warning: control may reach end of non-void function [-Wreturn-type]
    }
    ^
1 warning generated.