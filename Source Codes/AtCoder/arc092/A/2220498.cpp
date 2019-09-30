#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Dinic {
public:
    Dinic(int nElement) {
        m_edges = vector< vector<Edge> >(nElement);
        m_level = vector<int>(nElement);
        m_iter = vector<int>(nElement);
    }
    void addEdge(int from, int to, int cap) {
        m_edges[from].push_back(Edge(to, cap, m_edges[to].size()));
        m_edges[to].push_back(Edge(from, 0, m_edges[from].size()-1));
    }
    int maxFlow(int s, int t) {
        int flow = 0;
        for (;;) {
            bfs(s);
            if (m_level[t] < 0) break;
            fill(m_iter.begin(), m_iter.end(), 0);
            int f = 0;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
private:
    struct Edge {
        int to, cap, rev;
        Edge(int t, int c, int r):to(t),cap(c),rev(r){}
    };
    static const int INF = 1000000000;
    vector< vector<Edge> > m_edges;
    vector<int> m_level;
    vector<int> m_iter;
    void bfs(int s) {
        fill(m_level.begin(), m_level.end(), -1);
        m_level[s] = 0;
        queue<int> que;
        que.push(s);
        while (que.size() > 0) {
            int v = que.front(); que.pop();
            for (int i = 0; i < m_edges[v].size(); i++) {
                Edge& e = m_edges[v][i];
                if (e.cap > 0 && m_level[e.to] == -1) {
                    m_level[e.to] = m_level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = m_iter[v]; i < m_edges[v].size(); i++) {
            Edge& e = m_edges[v][i];
            if (e.cap > 0 && m_level[e.to] > m_level[v]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    m_edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};



using P = pair<int, int>;

int n;
vector<P> a;
vector<P> b;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    for (int i = 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        b.push_back(make_pair(x, y));
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    Dinic d = Dinic(2 * n + 2);
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) {
            if (a[i].first < b[j].first && a[i].second < b[j].second) {
                d.addEdge(i + 1, j + n + 1, 1);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        d.addEdge(0, i + 1, 1);
        d.addEdge(i + n + 1, 2 * n + 1, 1);
    }

    cout << d.maxFlow(0, 2 * n + 1) << endl;
}