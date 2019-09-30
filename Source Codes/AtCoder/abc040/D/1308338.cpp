#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct UnionFind{
    vector<int> data;
    UnionFind(int size) : data(size, -1){}
    bool unionSet(int x, int y){
        x = root(x);
        y = root(y);
        if (x != y){
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {return root(x) == root(y);}
    int root(int x) {return data[x] < 0 ? x : data[x] = root(data[x]);}
    int size(int x) {return -data[root(x)];}
};


int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> yab;
    for (int m = 0; m != M; ++m){
        int a, b, y;
        cin >> a >> b >> y;
        yab.emplace_back(make_tuple(y, a - 1, b - 1));
    }
    sort(yab.begin(), yab.end());
    int Q;
    cin >> Q;
    vector<tuple<int, int, int>> wvq;
    for (int q = 0; q != Q; ++q){
        int v, w;
        cin >> v >> w;
        wvq.emplace_back(make_tuple(w, v - 1, q));
    }
    sort(wvq.begin(), wvq.end(), greater<>());
    UnionFind uf(N);
    vector<int> ans(Q, 0);
    for (auto &wvqi : wvq){
        int w, v, q;
        tie(w, v, q) = wvqi;
        while(not yab.empty()){
            int y, a, b;
            tie(y, a, b) = yab.back();
            if (y <= w) break;
            uf.unionSet(a, b);
            yab.pop_back();
        }
        ans[q] = uf.size(v);
    }
    for (auto a : ans) cout << a << endl;
    return 0;
}