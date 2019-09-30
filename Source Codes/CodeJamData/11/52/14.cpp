#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

const int maxn = 11111;
int counts[maxn];

vector<int> L, R;
int n;

bool check(int limit)
{
    multiset<int> S(R.begin(), R.end());
    for (int i = 0; i < n; i++) {
        multiset<int>::iterator it = S.lower_bound(L[i] + limit);
        if (it == S.end())
            return false;
        S.erase(it);
    }
    return true;
}

int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
        memset(counts, 0, sizeof(counts));

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int ai;
            scanf("%d", &ai);
            counts[ai]++;
        }

        L.clear();
        R.clear();
        for (int i = 0; i + 1 < maxn; i++) {
            int delta = counts[i+1] - counts[i];
            while (delta > 0) {
                L.push_back(i);
                delta --;
            }
            while (delta < 0) {
                R.push_back(i);
                delta ++;
            }
        }

        n = L.size();
        int lo = 0, hi = maxn;
        while (lo < hi) {
            int mid = lo + hi >> 1;
            if (check(mid + 1)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (n == 0)
            lo = 0;
        printf("Case #%d: %d\n", ++cas, lo);
    }
}
