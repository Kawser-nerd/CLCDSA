#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i,m,n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define debug(x) #x << " = " << (x) << " "
using ll = long long;
using namespace std;
constexpr size_t max_n = 200000;
bool a[max_n+1];
int main() {
    int n, k; scanf("%d%d", &n, &k);
    repeat (i,n) { char c; scanf(" %c", &c); a[i] = (c == 'A'); }
    int m = n;
    a[m+1] = false;
    while (k --) {
        if (a[0]) {
            a[0] = false;
        } else {
            repeat (i,m) a[i] = not a[i+1];
        }
        while (2 <= m and not a[m-2] and a[m-1]) m -= 2;
        if (m == 0) break;
        if (m == 1) k %= 2;
    }
    repeat (i,n) printf("%c", a[i] ? 'A' : 'B');
    printf("\n");
    return 0;
}