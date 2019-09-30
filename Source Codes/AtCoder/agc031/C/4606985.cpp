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

uint64_t popcnt(uint64_t n)
{
    uint64_t c = 0;
    c = (n & 0x5555555555555555) + ((n>>1) & 0x5555555555555555);
    c = (c & 0x3333333333333333) + ((c>>2) & 0x3333333333333333);
    c = (c & 0x0f0f0f0f0f0f0f0f) + ((c>>4) & 0x0f0f0f0f0f0f0f0f);
    c = (c & 0x00ff00ff00ff00ff) + ((c>>8) & 0x00ff00ff00ff00ff);
    c = (c & 0x0000ffff0000ffff) + ((c>>16) & 0x0000ffff0000ffff);
    c = (c & 0x00000000ffffffff) + ((c>>32) & 0x00000000ffffffff);
    return(c);
}

void dfs(vector<int>& ans, vector<int> fixed, int a, int b, int i, int n) {
    ans[i] = a;
    ans[i + (1 << n) - 1] = b;

    if (n == 1) {
        return;
    }

    int j = -1;
    for (int k = 0; k < fixed.size(); k++) {
        if (!fixed[k] && ((a >> k) & 1) != ((b >> k) & 1)) {
            j = k;
            break;
        }
    }

    fixed[j] = 1;


    for (int k = 0; k < (1 << (n - 1)); k++) {
        if ((a >> j) & 1) {
            ans[i + k] = ans[i + k] | (1 << j);
        } else {
            ans[i + k + (1 << (n - 1))] = ans[i + k + (1 << (n - 1))] | (1 << j);
        }
    }


    for (int k = 0; k < fixed.size(); k++) {
        if (!fixed[k]) {

            int c = a ^ (1 << k);
            dfs(ans, fixed, a, c, i, n - 1);

            for (int l = 0; l < fixed.size(); l++) {
                if (fixed[l]) {
                    c = c & ~(1 << l);
                    c = c | (b & (1 << l));
                }
            }

            dfs(ans, fixed, c, b, i + (1 << (n - 1)), n - 1);

            break;
        }
    }    
}

int main() {
    int n;
    int a, b;
    in(n, a, b);

    if (popcnt(a) % 2 == popcnt(b) % 2) {
        out("NO");
        return 0;   
    }

    int m = 1 << n;

    vector<int> ans(m);
    vector<int> fixed(n);

    dfs(ans, fixed, a, b, 0, n);

    out("YES");

    vout(ans, m);

    for (int i = 0; i < m - 1; i++) {
        assert(popcnt(ans[i] ^ ans[i + 1]) == 1);
    }
}