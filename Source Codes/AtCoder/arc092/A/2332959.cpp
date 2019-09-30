/*** Template Begin ***/

#define USING_BOOST
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

auto init_ = [] {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed;
    return 0;
}();

template <typename T>
inline T in() {
    T x;
    std::cin >> x;
    return x;
}

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

/*** Template End ***/

struct FordFulkerson {
    struct Edge {
        int to, cap, rev;
    };

    vector<vector<Edge>> graph;
    vector<bool> used;

    static const int inf = 1 << 28;

    FordFulkerson(int n) : graph(n), used(n) {}

    FordFulkerson(const vector<vector<int>> &g)
        : graph(vector<vector<Edge>>(g.size())), used(g.size()) {
        for (int i : rep(0, g.size())) {
            for (int to : g[i]) {
                add_edge(i, to, 1);
            }
        }
    }

    void add_edge(int from, int to, int cap) {
        graph[from].push_back((Edge){to, cap, (int)graph[to].size()});
        graph[to].push_back((Edge){from, 0, (int)graph[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            fill(used, false);
            int f = dfs(s, t, inf);
            if (f == 0) return flow;
            flow += f;
        }
    }

   private:
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (auto &e : graph[v]) {
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

struct Dinic {
    struct Edge {
        int to, cap, rev;
    };

    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> iter;

    static const int inf = 1 << 28;

    Dinic(int n) : graph(n), level(n), iter(n) {}

    Dinic(const vector<vector<int>> &g)
        : graph(vector<vector<Edge>>(g.size())),
          level(g.size()),
          iter(g.size()) {
        for (int i : rep(0, g.size())) {
            for (int to : g[i]) {
                add_edge(i, to, 1);
            }
        }
    }

    void add_edge(int from, int to, int cap) {
        graph[from].push_back((Edge){to, cap, (int)graph[to].size()});
        graph[to].push_back((Edge){from, 0, (int)graph[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) {
                return flow;
            }
            fill(iter, 0);
            int f;
            while ((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
    }

   private:
    void bfs(int s) {
        fill(level, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (auto &e : graph[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;

        for (int &i = iter[v]; i < graph[v].size(); ++i) {
            Edge &e = graph[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

int min_cut(const vector<vector<int>> &graph, int s, int t) {
    Dinic dinic(graph.size());

    for (int i : rep(0, graph.size())) {
        for (int to : graph[i]) {
            dinic.add_edge(i, to, 1);
        }
    }

    return dinic.max_flow(s, t);
}

int main() {
    int n;

    in(n);

    vector<pair<int, int>> r(n), b(n);

    for (int i : rep(0, n)) {
        in(r[i].first, r[i].second);
    }

    for (int i : rep(0, n)) {
        in(b[i].first, b[i].second);
    }

    Dinic dinic(2 * n + 2);

    for (int i : rep(0, n)) {
        for (int j : rep(0, n)) {
            if (r[i].first < b[j].first && r[i].second < b[j].second) {
                dinic.add_edge(i, j + n, 1);
            }
        }
    }

    for (int i : rep(0, n)) {
        dinic.add_edge(2 * n, i, 1);
        dinic.add_edge(i + n, 2 * n + 1, 1);
    }

    out(dinic.max_flow(2 * n, 2 * n + 1));
}