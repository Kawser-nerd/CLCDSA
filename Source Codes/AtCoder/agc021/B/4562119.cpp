/*** Template Begin ***/

#pragma region template

#define USING_NAMESPACE

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef int64_t i64;
typedef uint64_t u64;

auto init_ = [] {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed;
    return 0;
}();

template <typename T>
inline void in(T &x) {
    std::cin >> x;
}

template <typename T, typename... Ts>
inline void in(T &t, Ts &... ts) {
    std::cin >> t;
    in(ts...);
}

template <typename T, typename U = std::vector<T>>
inline U vin(int n) {
    U v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    return v;
}

template <typename T, typename U = std::vector<T>, typename V = std::vector<U>>
inline V vin(int h, int w) {
    V vv(h, U(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> vv[i][j];
        }
    }
    return vv;
}

template <typename T>
inline void out(const T &x) {
    std::cout << x << std::endl;
}

template <char delimiter = ' ', typename T, typename... Ts>
inline void out(const T &t, const Ts &... ts) {
    std::cout << t << delimiter;
    out(ts...);
}

template <char delimiter = ' ', typename T>
inline void vout(const T &v, int n) {
    for (int i = 0; i < n; ++i) {
        if (i) std::cout << delimiter;
        std::cout << v[i];
    }
    std::cout << std::endl;
}

template <char delimiter = ' ', typename T>
inline void vout(const T &v, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (j) std::cout << delimiter;
            std::cout << v[i][j];
        }
        std::cout << std::endl;
    }
}

template <typename T, size_t D>
struct multi_vector_type {
    using type = std::vector<typename multi_vector_type<T, D - 1>::type>;
};

template <typename T>
struct multi_vector_type<T, 1> {
    using type = std::vector<T>;
};

template <typename T>
struct multi_vector_type<T, 0> {
    using type = T;
};

template <typename T, size_t D>
using multi_vector = typename multi_vector_type<T, D>::type;

template <typename T, size_t D, class = typename std::enable_if<D == 0>::type>
T make_vector(const T &val = T()) {
    return val;
}

template <typename T, size_t D = 1, typename... Ts,
          class = typename std::enable_if<D != 0>::type>
multi_vector<T, D> make_vector(size_t n, Ts &&... args) {
    return multi_vector<T, D>(n, make_vector<T, D - 1>(args...));
}

namespace detail {

template <typename F>
struct Debug {
    const char *delim_ = "\n";
    F fun;

    Debug(F f) : fun(f) {}

    ~Debug() { fun(delim_); }

    Debug &delim(const char *d) {
        delim_ = d;
        return *this;
    }
};

std::deque<std::string> split(const std::string &s, char c) {
    std::deque<std::string> v;
    std::stringstream ss(s);
    std::string x;
    while (std::getline(ss, x, c)) v.emplace_back(x);
    return v;
}

template <typename T>
void deb(const char *delim, std::deque<std::string> v, T a) {
    std::cerr << v[0].substr(v[0][0] == ' ', v[0].length()) << " = " << a
              << '\n';
    std::cerr << std::flush;
}

template <typename T, typename... Args>
void deb(const char *delim, std::deque<std::string> v, T a, Args... args) {
    std::cerr << v[0].substr(v[0][0] == ' ', v[0].length()) << " = " << a
              << delim;
    v.pop_front();
    deb(delim, std::move(v), args...);
}

template <typename... Args>
auto wrap(std::deque<std::string> v, Args... args) {
    auto f = [=](const char *delim = "\n") { deb(delim, v, args...); };

    return Debug<decltype(f)>(f);
}
}

#define debug(args...) ::detail::wrap(::detail::split(#args, ','), args)

#ifdef USING_BOOST

#include <boost/math/common_factor.hpp>
#include <boost/range.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/numeric.hpp>

inline auto rep(int begin, int end) {
    if (begin > end) {
        return boost::irange(0, 0);
    } else {
        return boost::irange(begin, end);
    }
}

inline auto rep(int begin, int end, int step) {
    if ((step > 0 && begin > end) || (step < 0 && begin < end)) {
        return boost::irange(0, 0, step);
    } else {
        return boost::irange(begin, end, step);
    }
}

#endif

#ifdef USING_NAMESPACE
using namespace std;

#ifdef USING_BOOST
using namespace boost;
using namespace boost::adaptors;
#endif
#endif

#pragma endregion

/*** Template End ***/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

#define ALL(c) c.begin(), c.end()
#define FOR(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define fst first
#define snd second

typedef long double Value;
typedef complex<Value> Point;
#define X real()
#define Y imag()
Value dot(Point a, Point b)   { return real(conj(a)*b); }
Value cross(Point a, Point b) { return imag(conj(a)*b); }
Value dist2(Point a, Point b) { return dot(a-b, a-b); }

int ccw(Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b,c) > 0)      return +1; // counter clockwise
  if (cross(b,c) < 0)      return -1; // clockwise
  if (dot(b,c) < 0)        return +2; // c--a--b on line
  if (dot(b,b) < dot(c,c)) return -2; // a--b--c on lne
  return 0;
}

// Convex Hull
//
// Algorithm:
//   Andrew's monotone chain
namespace std { 
  bool operator < (Point a, Point b) { // bottom-left
    return a.Y != b.Y ? a.Y < b.Y : a.X < b.X; 
  }
}
vector<Point> convexHull(vector<Point> p) {
  int n = p.size(), k = 0;
  vector<Point> h(2*n);
  sort(ALL(p));
  for (int i = 0; i < n; h[k++] = p[i++]) 
    while (k >= 2 && ccw(h[k-2], h[k-1], p[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; h[k++] = p[i--]) 
    while (k >= t && ccw(h[k-2], h[k-1], p[i]) <= 0) --k;
  return vector<Point>(h.begin(), h.begin() + k - (k > 1));
}

int main() {
    int n;
    in(n);

    vector<Point> p(n);
    
    for (int i = 0; i < n; i++) {
        Value x, y;
        in(x, y);

        p[i] = Point(x, y);
    }

    auto s = convexHull(p);

    vector<double> ans(n, 0.0);

    double pi = acos(-1);

    cout << fixed << setprecision(12);

    for (int i = 0; i < s.size(); i++) {

        Point d1 = s[(i + 1) % s.size()] - s[i];
        Point d2 = s[(i + s.size() - 1) % s.size()] - s[i];

        double r = arg(d2) - arg(d1);

        if (r < 0) {
            r += 2 * pi;
        }

        double x = (pi - r) / (2 * pi);

        int ind = find(p.begin(), p.end(), s[i]) - p.begin();

        ans[ind] = x;
    }

    for (int i = 0; i < n; i++) {
        out(ans[i]);
    }
}