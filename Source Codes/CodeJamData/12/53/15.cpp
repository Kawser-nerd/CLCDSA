#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
ll M, F;
typedef pair<ll, ll> pll;
vector<pll> PS;


const ll INF = (ll)4e18;

inline ll safeAdd(ll p1, ll p2) {
    return min(p1 + p2, INF);
}

inline ll safeMul(ll p1, ll p2) {
    if (p2 == 0)
        return 0;
    if (INF / p2 < p1)
        return INF;
    else 
        return min(p1 * p2, INF);
}

ll getSingleShipmentCost(ll days) {
    if (days > PS.back().first) {
        return INF;
    }
    ll result = 0;
    ll leftBorder = 0;
    for (int i = 0; i < N; ++i) {
        result = safeAdd(result, safeMul(PS[i].second, min(PS[i].first, days) - leftBorder));
        if (PS[i].first < days)
            leftBorder = PS[i].first;
        else
            break;
    }
    return result;
}

ll getCost(ll o, ll days) {
    ll lb = days / o;
    ll rb = lb + 1;
    ll cr = days % o;
    ll cl = o - cr;
    return safeAdd(safeMul(o, F), safeAdd(safeMul(getSingleShipmentCost(lb), cl), safeMul(getSingleShipmentCost(rb), cr)));
}

ll minMoney(ll days) {
    ll left = (days - 1) / PS.back().first + 1;
    ll right = M / F;
    while (right - left > 2) {
        ll m1 = (left + right) / 2;
        ll m2 = m1 + 1;

        //ll cl = getCost(left, days);
        ll c1 = getCost(m1, days);
        ll c2 = getCost(m2, days);
        //ll cr = getCost(right, days);
        if (c1 > c2) {
            left = m1;
        } else
            right = m2;
    }
    ll res = INF;
    for (ll i = left; i <= right; ++i) {
        res = min(res, getCost(i, days));
    }
    return res;
}

int main(void) {
    int T;
    cin >> T;
    for (int testNo = 1; testNo <= T; ++testNo) {
        cin >> M >> F >> N;
        PS.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> PS[i].second >> PS[i].first;
            PS[i].first += 1;
        }
        sort(PS.begin(), PS.end());
        vector<pll> nps;
        for (int i = 0; i < N; ++i) {
            while (!nps.empty()) {
                if (nps.back().second >= PS[i].second)
                    nps.pop_back();
                else
                    break;
            }
            if (!nps.empty() && nps.back().first == PS[i].first)
                continue;
            nps.push_back(PS[i]);
        }
        PS.assign(nps.begin(), nps.end());
        N = (int)nps.size();
        ll left = 0;
        ll right = M+1;
        while (right - left != 1) {
            ll mid = (left + right) / 2;
            if (minMoney(mid) > M) {
                right = mid;
            } else
                left = mid;
        }
        cout << "Case #" << testNo << ": " << left << endl;
    }
    return 0;
}
