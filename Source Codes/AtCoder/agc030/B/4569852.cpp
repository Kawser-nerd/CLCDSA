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

map<tuple<int, int, int>, pair<i64, vector<int>>> memo;

i64 l;
int n;
    
vector<i64> x;

pair<i64, vector<int>> dfs(int i, int j, int k) {
    if (i + 1 == j) {
        return {0, vector<int>()};
    }

    auto t = make_tuple(i, j, k);

    if (memo.count(t)) {
        return memo[t];
    } 

    pair<i64, vector<int>> ret;

    if (k == i) {
        /*ret = max(
            x[i + 1] - x[i] + dfs(i + 1, j, i + 1),
            x[i] + l - x[j - 1] + dfs(i, j - 1, j - 1)  
        );*/

        auto r1 = dfs(i + 1, j, i + 1);
        auto r2 = dfs(i, j - 1, j -1);

        i64 c1 = r1.first + x[i + 1] - x[i];
        i64 c2 = r2.first + x[i] + l - x[j - 1];

        if (c1 > c2) {
            ret.first = c1;
            ret.second = r1.second;
            ret.second.push_back(i + 1);
        } else {
            ret.first = c2;
            ret.second = r2.second;
            ret.second.push_back(j - 1);
        }
    } else if (k == j) {
        /*ret = max(
            x[j] - x[j - 1] + dfs(i, j - 1, j - 1),
            l - x[j] + x[i + 1] + dfs(i + 1, j, i + 1)
        );*/
        auto r1 = dfs(i, j - 1, j - 1);
        auto r2 = dfs(i + 1, j, i + 1);

        i64 c1 = r1.first + x[j] - x[j - 1];
        i64 c2 = r2.first + l - x[j] + x[i + 1];

        if (c1 > c2) {
            ret.first = c1;
            ret.second = r1.second;
            ret.second.push_back(j - 1);
        } else {
            ret.first = c2;
            ret.second = r2.second;
            ret.second.push_back(i + 1);
        }

    } else {
        assert(false);
    }

    return memo[t] = ret;
}

int main() {
    in(l, n);

    x = vin<i64>(n);

    vector<i64> y(n);
    
    for (int i = 0; i < n; i++) {
        y[i] = l - x[i];
    }

    i64 ans = 0;

    vector<i64> cumsum1(n), cumsum2(n);

    cumsum1[0] = x[0];
    for (int i = 1; i < n; i++) {
        cumsum1[i] = cumsum1[i - 1] + x[i];
    }

    cumsum2[n - 1] = y[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        cumsum2[i] = cumsum2[i + 1] + y[i];
    }

    for (int i = 0; i < n; i++) {
        // x[i] ?????????

        if (i == 0) {
            ans = max(ans, y[i + 1] + max(x[i + 1] - x[i], y[i + 1] + x[i]));
        } else if (i == n - 1) {
            ans = max(ans, x[i - 1] + max(x[i] - x[i - 1], x[i - 1] + y[i]));
        } else {
            {
                // x[i - 1] ?????2????????

                i64 s = 0;

                int j1 = i - 1;
                int j2 = i + 1;

                vector<int> v1, v2;

                s += x[j1--];

                int k1 = j1 + 1;
                int k2 = n - j2;

                if (j1 >= 0) {
                    s += 2 * cumsum1[j1];
                }

                s += 2 * cumsum2[j2];

                if (k2 <= k1) {
                    if (j1 - k2 >= 0) {
                        s -= 2 * cumsum1[j1 - k2];
                    }
                } else {
                    if (j2 + k1 + 1 < n) {
                        s -= 2 * cumsum2[j2 + k1 + 1];
                    }
                }

                ans = max(ans, s + max(x[i] - x[i - 1], x[i - 1] + y[i]));
            }

            {
                // x[i + 1] ?????2????????

                debug(i);

                i64 s = 0;

                int j1 = i - 1;
                int j2 = i + 1;

                vector<int> v1, v2;

                s += y[j2++];

                int k1 = j1 + 1;
                int k2 = n - j2;

                if (j2 < n) {
                    s += 2 * cumsum2[j2];
                }

                s += 2 * cumsum1[j1];

                if (k1 <= k2) {
                    if (j2 + k1 < n) {
                        s -= 2 * cumsum2[j2 + k1];
                    }
                } else {
                    if (j1 - k2 - 1 >= 0) {
                        s -= 2 * cumsum1[j1 - k2 - 1];
                    }
                }

                ans = max(ans, s + max(x[i + 1] - x[i], y[i + 1] + x[i]));
            }
        }
    }

    out(ans);
}