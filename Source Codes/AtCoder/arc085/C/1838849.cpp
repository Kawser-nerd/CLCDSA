#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

template<typename T>
class Dinic {
    struct edge {
        int to;
        T cap;
        int rev;
    };

    const T INF;
    vector< vector<edge> > graph;
    vector<T> min_cost;
    vector<int> iter;

    bool bfs(int s, int t) {
        min_cost.assign(graph.size(), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int q = que.front();
            que.pop();
            for (edge &e : graph[q]) {
                if (e.cap > 0 && min_cost[e.to] == -1) {
                    min_cost[e.to] = min_cost[q] + 1;
                    que.push(e.to);
                }
            }
        }
        return (min_cost[t] != -1);
    }

    T dfs(int idx, const int t, T flow) {
        if (idx == t) return flow;
        for (int &i = iter[idx]; i < graph[idx].size(); i++) {
            edge &e = graph[idx][i];
            if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
                T d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    public:
        Dinic(int n) : INF(numeric_limits<T>::max()/100) {
            graph.resize(n);
        }

        void add_edge(int from, int to, T cap) {
            graph[from].push_back((edge){to, cap, static_cast<int>(graph[to].size())});
            graph[to].push_back((edge){from, 0, static_cast<int>(graph[from].size())-1}); //add reverse edge
        }

        T max_flow(int s, int t) {
            T flow = 0;
            while (bfs(s, t)) {
                iter.assign(graph.size(), 0);
                T f = 0;
                while ((f = dfs(s, t, INF)) > 0) {
                    flow += f;
                }
            }
            return flow;
        }
};


void solve(long long N, vector<long long> a){
    Dinic<long long> G(N+2);
    long long ret = 0;
    const long long INF = numeric_limits<long long>::max()/100;
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) {
            ret += a[i];
            G.add_edge(0, i+1, a[i]);
            G.add_edge(i+1, N+1, 0);
        } else {
            G.add_edge(0, i+1, 0);
            G.add_edge(i+1, N+1, - a[i]);
        }
        for (int j = i+i+1; j < N; j += i+1) {
            G.add_edge(j+1, i+1, INF);
        }
    }
    ret -= G.max_flow(0, N+1);
    std::cout << ret << std::endl;
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long N;
    scanf("%lld",&N);
    vector<long long> a(N-1+1);
    for(int i = 0 ; i <= N-1 ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, a);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}