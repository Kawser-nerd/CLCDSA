#include <cstdio>
#include <iostream>
#include <unordered_set>

template <class T>
struct Point {
    static_assert(std::is_integral<T>(), "Fuck you");

    Point() = default;
    Point(T _x, T _y)
        : x(_x)
        , y(_y)
    {
        x = _x;
        y = _y;
    }
    Point(const Point&) = default;
    Point(Point&&) = default;
    Point& operator =(const Point&) = default;
    Point& operator =(Point&&) = default;
    ~Point() = default;

    Point operator +(const Point& p) const {
        return Point<T>(x + p.x, y + p.y);
    }
    Point& operator +=(const Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point operator -(const Point& p) const {
        return Point<T>(x - p.x, y - p.y);
    }
    Point& operator -=(const Point& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    T x, y;
};

const int N = 2e5 + 5;

std::unordered_set <int> e[N];

bool solve() {
    int n, m, u, v;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        e[u].insert(v);
        e[v].insert(u);
    }
    for (auto i : e[1]) {
        if (e[i].count(n)) {
            std::cout << "POSSIBLE\n";
            return 0;
        }
    }
    std::cout << "IMPOSSIBLE";

    return 0;
}

int main() {
#ifdef LOCALHOST
    freopen("input", "r", stdin);
#endif
    while (solve());

    return 0;
}