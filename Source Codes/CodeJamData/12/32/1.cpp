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
#define ZERO(x) memset(x,0 ,sizeof(x))

typedef long double LD;

LD time_needed(LD speed, LD acc, LD distance) {
    if (distance < 1e-9) {
        return 0;
    }
    // x * speed + 0.5 * acc * x^2 == distance
    LD a = 0.5 * acc;
    LD b = speed;
    LD c = - distance;
    LD del = b * b - 4 * a * c;
    return (-b + sqrtl(del)) / (2 * a);
}

void alg() {
    LD distance;
    scanf("%Lf", &distance);

    int n, n_queries;

    scanf("%d %d", &n, &n_queries);

    vector<LD> time(n);
    vector<LD> position(n);
    vector<LD> speed(n);

    for (int i = 0; i < n; ++i) {
        scanf("%Lf %Lf", &time[i], &position[i]);
    }

    while (position[n - 1] > distance) {
        if (position[n - 2] < distance - 1e-9) {
            time[n - 1] = time[n - 2] + ((distance - position[n - 2]) / (position[n - 1] - position[n - 2])) * (time[n - 1] - time[n - 2]);
            position[n - 1] = distance;
            break;
        } else {
            --n;
        }
    }

    static int case_no = 0;
    printf("Case #%d:\n", ++case_no);

    for (int i = 0; i < n_queries; ++i) {
        LD acc;
        scanf("%Lf", &acc);
        LD result = 0;
        for (int j = 0; j < n; ++j) {
            result = max(result, time[j] - time_needed(0, acc, position[j]));
        }
        printf("%.10Lf\n", result + time_needed(0, acc, distance));
    }
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        alg();
    }
}
