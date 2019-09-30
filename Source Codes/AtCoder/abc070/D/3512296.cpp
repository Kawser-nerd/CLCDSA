#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

constexpr long MAXC = 2E9;

void finddist(int pwd, int parent, vector<unordered_map<int, long>> &edge, vector<long> &kdistance) {
    kdistance[pwd] = kdistance[parent] + edge[parent][pwd];
    for (auto&& itr : edge[pwd]) {
        if (itr.first == parent) continue;
        finddist(itr.first, pwd, edge, kdistance);
    }
}

int main() {
    int nodes;
    cin >> nodes;
    vector<unordered_map<int, long>> edge(nodes + 1);
    for (int i = 0; i < nodes - 1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].emplace(b, c);
        edge[b].emplace(a, c);
    }

    int problems, k;
    cin >> problems >> k;
    vector<long> kdistance(nodes + 1, MAXC);
    kdistance[k] = 0;

    for (auto&& itr : edge[k]) {
        finddist(itr.first, k, edge, kdistance);
    }

    for (int i = 0; i < problems; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        cout << kdistance[x] + kdistance[y] << endl;
    }
}