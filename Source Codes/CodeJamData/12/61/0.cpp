#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl

struct Event {
    int time;
    int zombie;
};

bool operator < (const Event& a, const Event& b) {
    return a.time < b.time;
}

struct Zombie {
    int x, y;
    int start;
    vector<int> my_events;
};

void alg() {
    int n;
    cin >> n;
    vector<Zombie> zombies(n);
    vector<Event> events;
    events.reserve(1001 * n);
    for (int i = 0; i < n; ++i) {
        cin >> zombies[i].x >> zombies[i].y >> zombies[i].start;
        for (int j = zombies[i].start; j <= zombies[i].start + 1000; ++j) {
            Event event;
            event.time = j;
            event.zombie = i;
            events.PB(event);
        }
    }

    sort(ALL(events));

    for (int i = 0; i < (int) events.size(); ++i) {
        zombies[events[i].zombie].my_events.push_back(i);
    }

    vector<int> dp(events.size(), 0);
    for (int i = 0; i < (int) events.size(); ++i) {
        int needed = max(abs(zombies[events[i].zombie].x), abs(zombies[events[i].zombie].y)) * 100;
        if (needed <= events[i].time) {
            dp[i] = 1;
        }
    }
    int result = 0;
    for (int i = 0; i < (int) events.size(); ++i) {
        if (dp[i] == 0) {
            continue;
        }
        result = max(result, dp[i]);
        const Zombie& cur = zombies[events[i].zombie];
        FORE (it, zombies) {
            if (it - zombies.begin() != events[i].zombie) {
                int needed = max(abs(cur.x - it->x), abs(cur.y - it->y)) * 100;
                needed = events[i].time + max(needed, 750);
                if (needed <= it->start + 1000) {
                    int ev = it->my_events[max(0, needed - it->start)];
                    dp[ev] = max(dp[ev], dp[i] + 1);
                }
            }
        }
    }
    cout << result << endl;
}

int main() {
    int n_cases;
    cin >> n_cases;
    for (int test_case = 1; test_case <= n_cases; ++test_case) {
        cout << "Case #" << test_case << ": ";
        alg();
    }
}
