#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int n;
vector<string> pws;

char getL33t(char ch) {
    switch (ch) {
    case 'o':
        return '0';
    case 'i':
        return '1';
    case 'e':
        return '3';
    case 'a':
        return '4';
    case 's':
        return '5';
    case 't':
        return '7';
    case 'b':
        return '8';
    case 'g':
        return '9';
    default:
        return ch;
    }
}

typedef long long ll;

namespace FlowsAndRelatedAlgorithms {
    struct TEdge {
        int from, to;
        ll capacity, flow;
        ll cost;
        TEdge* reverse;
    };
    typedef TEdge* PEdge;

    TEdge edgePool[1000000];
    int edgePoolPtr = 0;

    typedef vector<PEdge> ve;
    vector< ve > edges;
    
    int SOURCE, TARGET;

    TEdge* AddEdge(int from, int to, ll capacity, ll cost = 0) {
        TEdge* e1 = &edgePool[edgePoolPtr++];
        TEdge* e2 = &edgePool[edgePoolPtr++];
        TEdge fw = {from, to, capacity, 0, cost, e2};
        TEdge bw = {to, from, 0, 0, cost, e1};
        *e1 = fw;
        *e2 = bw;
        edges[from].push_back(e1);
        edges[to].push_back(e2);
        return e1;
    }

    inline ll AvailableCapacity(const TEdge* p) {
        return (p->capacity - p->flow);
    }

    namespace FordFulkersonSimple { // simple Ford-Fulkerson, relaxing by one flow per time
        vector<bool> been;

        bool ff_dfs(int p) { 
            if (p == TARGET) return true;
            if (been[p]) return false;
            been[p] = true;
            for (ve::iterator it = edges[p].begin(); it != edges[p].end(); it++) {
                TEdge* ite = *it;
                if (ite->flow < ite->capacity && ff_dfs(ite->to)) {
                    ite->flow++;
                    ite->reverse->flow--;
                    return true;
                }
            }
            return false;
        }
    }

    
    class TDinic {
        vector<int> Distances;
        vector<size_t> Ptr;
        int N;
        void BFS() {
            deque<int> q;
            Distances.assign(N, -1);
            Distances[SOURCE] = 0;
            q.push_back(SOURCE);
            while (!q.empty()) {
                int p = q.front();
                q.pop_front();
                for (size_t i = 0; i < edges[p].size(); i++) {
                    if (!AvailableCapacity(edges[p][i]))
                        continue;
                    int c = edges[p][i]->to;
                    if (Distances[c] == -1) {
                        Distances[c] = Distances[p] + 1;
                        q.push_back(c);
                    }
                }
            }
        }
        ll DFS(int p, ll fl) {
            if (fl == 0)
                return 0;
            if (p == TARGET)
                return fl;
            ll res = 0;

            for (size_t &i = Ptr[p]; Ptr[p] < edges[p].size() && fl != 0; ++i) {
                if (!AvailableCapacity(edges[p][i])) {
                    continue;
                }
                if (Distances[edges[p][i]->from] + 1 != Distances[edges[p][i]->to])
                    continue;
                ll pushed = DFS(edges[p][i]->to, min(fl, AvailableCapacity(edges[p][i])));
                fl -= pushed;
                res += pushed;
                edges[p][i]->flow += pushed;
                edges[p][i]->reverse->flow -= pushed;
                if (fl == 0)
                    break;
            }
            return res;
        }
    public:
        TDinic() {
            N = (int)edges.size();
        }
        ll GetMaxFlow() {
            ll res = 0;
            for (;;) {
                BFS();
                Ptr.assign(N, 0);
                ll p = DFS(SOURCE, LLONG_MAX / 2);
                if (!p)
                    break;
                res += p;
            }
            return res;
        }
    };

}


int main(void) {
    int T;
    cin >> T;
    for (int testNo = 1; testNo <= T; ++testNo) {
        int k;
        cin >> k;
        string str;
        cin >> str;
        pws.clear();
        FlowsAndRelatedAlgorithms::edgePoolPtr = 0;
        /*for (size_t i = 0; i < str.length(); ++i) {
            char chs[] = {0, 0};
            chs[0] = str[i];
            pws.push_back(chs);
            chs[0] = getL33t(str[i]);
            pws.push_back(chs);
        }*/
        for (size_t i = 0; i+1 < str.length(); ++i) {
            char chs[3] = {0, 0, 0};
            chs[0] = str[i];
            chs[1] = str[i+1];
            pws.push_back(chs);
            chs[0] = getL33t(str[i]);
            pws.push_back(chs);
            chs[1] = getL33t(str[i+1]);
            pws.push_back(chs);
            chs[0] = str[i];
            pws.push_back(chs);
        }
        sort(pws.begin(), pws.end());
        pws.erase(unique(pws.begin(), pws.end()), pws.end());
        map<char, vi> ma1, ma2;
        n = (int)pws.size();
        for (int i = 0; i < n; ++i) {
            ma1[pws[i][0]].push_back(i);
            ma1[pws[i][1]].size();
            ma2[pws[i][1]].push_back(i);
            ma2[pws[i][0]].size();
        }
        int res1 = 0, res2 = 0;
        for each (auto it in ma1) {
            int s1 = (int)it.second.size();
            int s2 = (int)ma2[it.first].size();
            if (s1 > s2) {
                res1 += s1 - s2;
            } else
                res2 += s2 - s1;
        }
        cout << "Case #" << testNo << ": " << pws.size() + max(1, max(res1, res2)) << endl;

        /*using namespace FlowsAndRelatedAlgorithms;
        edges.clear();
        edges.resize(2*n + 2);
        SOURCE = 2*n;
        TARGET = 2*n + 1;
        for (int i = 0; i < n; ++i) {
            const vi& t = ma[pws[i][1]];
            AddEdge(SOURCE, i, 1);
            AddEdge(i + n, TARGET, 1);
            for each (int j in t) {
                AddEdge(i, j + n, 1);
            }
        }
        int res = */
    }
    return 0;
}
