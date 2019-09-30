#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

struct coin {
    ll a, b, c;
};

bool cmp(coin x, coin y) {
    return x.a - x.b < y.a - y.b;
}

ll ag[100005], au[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;
    int n = x + y + z;

    vector <coin> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i].a >> vec[i].b >> vec[i].c;

    sort(vec.begin(), vec.end(), cmp);

    priority_queue <ll, vector<ll>, greater<ll>> silver;
    for (int i = 0; i < y; i++) {
        silver.push(vec[i].b - vec[i].c);
        ag[y-1] += vec[i].b;
    }

    for (int i = y; i < y+z; i++) {
        ag[i] = ag[i-1];
        ll st = silver.top();
        ll dif = vec[i].b - vec[i].c;
        if (dif > st) {
            silver.pop();
            silver.push(dif);
            ag[i] += vec[i].b - st;
        } else {
            ag[i] += vec[i].c;
        }
    }

    priority_queue <ll, vector<ll>, greater<ll> > gold;
    for (int i = y + z; i < n; i++) {
        gold.push(vec[i].a - vec[i].c);
        au[y+z] += vec[i].a;
    }

    for (int i = y+z-1; i >= y; i--) {
        au[i] = au[i+1];
        ll gt = gold.top();
        ll dif = vec[i].a - vec[i].c;
        if (dif > gt) {
            gold.pop();
            gold.push(dif);
            au[i] += vec[i].a - gt;
        } else {
            au[i] += vec[i].c;
        }
    }

    ll ans = 0;
    for (int i = y-1; i < y+z; i++) ans = max(ans, ag[i] + au[i+1]);

    cout << ans << "\n";
    return 0;
}