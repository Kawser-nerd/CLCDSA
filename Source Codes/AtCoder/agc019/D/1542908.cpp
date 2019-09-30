#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool haveone(const string s) {
    for (auto &&item : s) {
        if (item == '1') {
            return true;
        }
    }
    return false;
}

int main() {
    string a, b;
    cin >> a >> b;

    const int n = a.length();

    if (!haveone(b)) {
        if (!haveone(a)){
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    auto ls = [&](const int p, const int s) {
        return (p - s + n + n) % n;
    };

    auto rs = [&](const int p, const int s) {
        return (p + s) % n;
    };

    auto dist = [&](const int p, const int q) {
        return min(abs(q - p), n - abs(q - p));
    };

    vector<int> mls(n, n), mrs(n, n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            continue;
        }
        for (int d = 0; d < n; ++d) {
            if (b[ls(i, d)] == '1') {
                mls[i] = min(mls[i], d);
            }
            if (b[rs(i, d)] == '1') {
                mrs[i] = min(mrs[i], d);
            }
        }
    }

    auto cost = [&](const int mxl, const int mxr, const int fls) {
        const int lpos = ls(0, mxl);
        const int rpos = rs(0, mxr);
        const int goal = ls(0, fls);
        const int lf = mxl * 2 + mxr + dist(rpos, goal);
        const int rf = mxr * 2 + mxl + dist(lpos, goal);
        return min(lf, rf);
    };

    int ans = 1 << 25;
    for (int fls = 0; fls < n; ++fls) {
        priority_queue<pair<int, int>> lrs;
        int add_cost = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1' && b[ls(i, fls)] == '0') {
                lrs.emplace(mls[i], mrs[i]);
            }
            if (a[i] == '0' && b[ls(i, fls)] == '1') {
                add_cost += 1;
            }
        }
        const int decr_cost = lrs.size();

        int maxr = 0;
        while (not lrs.empty()) {
            auto t = lrs.top();
            lrs.pop();

            const int maxl = t.first;
            const int tans = decr_cost + cost(maxl, maxr, fls) + add_cost;
            ans = min<int>(ans, tans);

            maxr = max(maxr, t.second);
        }
        ans = min<int>(ans, decr_cost + cost(0, maxr, fls) + add_cost);
    }

    cout << ans << endl;
    return 0;
}