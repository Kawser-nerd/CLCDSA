#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;

struct Point {
    int x;
    int y;
    int id;
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

static bool cmpx(Point const & p1, Point const & p2) {
    return p1.x < p2.x;
}
static bool cmpy(Point const & p1, Point const & p2) {
    return p1.y < p2.y;
}

struct Unionset {
    vector<int> parents;
    Unionset(int n) {
        parents = vector<int>(n, -1);
        for (int i = 0; i < n; i++) parents[i] = i;
    }
    int find(int i) {
        if (parents[i] == i) return i;
        int ret = find(parents[i]);
        parents[i] = ret;
        return ret;
    }
    void add(int i, int j) {
        int dadi = find(i);
        int dadj = find(j);
        if (dadi == dadj) return;
        parents[dadi] = dadj;
        return;
    }
    bool check(int i, int j) {
        int dadi = find(i);
        int dadj = find(j);
        return dadi==dadj;
    }
};

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<Point> towns(n, Point(0, 0));
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &towns[i].x, &towns[i].y);
        towns[i].id = i;
    }
    vector<Point> townx = towns;
    vector<Point> towny = towns;

    sort(townx.begin(), townx.end(), cmpx);
    sort(towny.begin(), towny.end(), cmpy);


    multimap<int, pair<int, int> > graph;

    for (int i = 1; i < n; i++) {
        graph.insert({townx[i].x - townx[i-1].x, {townx[i].id, townx[i-1].id}});
        graph.insert({towny[i].y - towny[i-1].y, {towny[i].id, towny[i-1].id}});
    }
    Unionset connect = Unionset(n);

    LL cost = 0;

    for (auto it = graph.begin(); it != graph.end(); it++) {
        int id1 = it->second.first;
        int id2 = it->second.second;
        if (it->first == 0) {
            connect.add(id1, id2);
        }
        else if (!connect.check(id1, id2)) {
            cost += it->first;
            connect.add(id1, id2);
        }
    }
    cout << cost << endl;

    return 0;


}