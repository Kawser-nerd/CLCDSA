//
// B - Checkpoints
//

#include <iostream>
#include <vector>

using namespace std;

struct checkpoint {
    int id, x, y;

    bool operator<(const checkpoint &right) const {
        return x == right.x ? id < right.id : x < right.x;
    }

    int distance(const pair<int, int> &s) {
        return abs(x - s.first) + abs(y - s.second);
    }
};

int main() {

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> S;
    vector<checkpoint> C;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        S.emplace_back(make_pair(a, b));
    }

    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        C.push_back((checkpoint) {i + 1, c, d});
    }

    sort(C.begin(), C.end());

    for (auto s: S) {
        int id, min_ = INT32_MAX;
        for (auto c: C) {
            if (abs(c.x - s.first) > min_) {
                break;
            }
            if (min_ > c.distance(s)) {
                id = c.id;
                min_ = c.distance(s);
            }
        }
        cout << id << endl;
    }
}