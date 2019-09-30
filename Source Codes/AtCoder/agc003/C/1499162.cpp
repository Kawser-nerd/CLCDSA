#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) y) { return (f)(begin(y), end(y), ## __VA_ARGS__); })(x)
using namespace std;
int main() {
    int n; scanf("%d", &n);
    vector<int> a(n); repeat (i,n) scanf("%d", &a[i]);
    unordered_set<int> x;
    for (int i = 0; i < n; i += 2) x.insert(a[i]);
    whole(sort, a);
    int ans = 0;
    for (int i = 1; i < n; i += 2) ans += x.count(a[i]);
    printf("%d\n", ans);
    return 0;
}