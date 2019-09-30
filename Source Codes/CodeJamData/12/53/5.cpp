#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

vector<LL> min_meals;
vector<LL> start_cost;
vector<LL> added_cost;

LL money;

LL get_meals_cost(LL meals) {
    int c = upper_bound(ALL(min_meals), meals) - min_meals.begin();
    --c;
    LL max_added = (money - start_cost[c]) / added_cost[c];
    if (money < start_cost[c] || max_added < meals - min_meals[c]) {
        return money + 1;
    } else {
        return start_cost[c] + added_cost[c] * (meals - min_meals[c]);
    }
}

LL get_cost(LL days, LL deliveries) {
    LL meals_per_delivery = days / deliveries;
    LL big_deliveries = days % deliveries;
    LL small_deliveries = deliveries - big_deliveries;
    LL big_cost = get_meals_cost(meals_per_delivery + 1);
    LL small_cost = get_meals_cost(meals_per_delivery);
    LL max_big = money / max(1LL, big_cost);
    LL max_small = money / max(1LL, small_cost);
    if (small_cost == 0) {
        max_small = small_deliveries + 1;
    }
    if (big_cost == 0) {
        max_big = big_deliveries + 1;
    }
    if (big_deliveries > max_big || small_deliveries > max_small) {
        return money + 1;
    } else {
        return min(money + 1, big_deliveries * big_cost + small_deliveries * small_cost);
    }
}

LL delivery_fee;

LL min_cost(LL days) {
    if (days == 0) {
        return 0;
    }
    LL l = 1;
    LL r = money + 1;
    while (l < r) {
        LL c = (l + r) / 2;
        LL a = get_cost(days, c);
        LL b = get_cost(days, c + 1);
        if (a >= money + 1 || b >= money + 1 || b - a + delivery_fee <= 0) {
            l = c + 1;
        } else {
            r = c;
        }
    }
    LL result = get_cost(days, l);
    if (result > money) {
        return money + 1;
    } else {
        LL max_fees = (money - result) / delivery_fee;
        if (max_fees < l) {
            return money + 1;
        }
        return result + l * delivery_fee;
    }
}

LL get_max_days() {
    LL l = 0;
    LL r = money;
    while (l < r) {
        LL c = (l + r + 1) / 2;
        if (min_cost(c) <= money) {
            l = c;
        } else {
            r = c - 1;
        }
    }
    return l;
}

struct Offer {
    LL max_meals;
    LL price;
};

bool operator < (const Offer& a, const Offer& b) {
    return a.price < b.price;
}

void alg() {
    int n;
    min_meals.clear();
    start_cost.clear();
    added_cost.clear();
    cin >> money >> delivery_fee >> n;
    vector<Offer> offers(n);
    for (int i = 0; i < n; ++i) {
        cin >> offers[i].price;
        cin >> offers[i].max_meals;
        ++offers[i].max_meals;
    }
    LL total = 0;
    LL last = 0;
    sort(ALL(offers));
    for (int i = 0; i < n; ++i) {
        if (offers[i].max_meals > last) {
            LL max_added = min(offers[i].max_meals - last, (money - total) / offers[i].price);
            if (max_added <= 0) {
                break;
            }
            min_meals.PB(last);
            start_cost.PB(total);
            added_cost.PB(offers[i].price);
            last += max_added;
            total += max_added * offers[i].price;
        }
    }
    min_meals.PB(last + 1);
    start_cost.PB(money + 1);
    added_cost.PB(1);
    static int case_no = 0;
    cout << "Case #" << ++case_no << ": " << get_max_days() << endl;
}

int main() {
    int d;
    cin >> d;
    while (d--) {
        alg();
    }
}
