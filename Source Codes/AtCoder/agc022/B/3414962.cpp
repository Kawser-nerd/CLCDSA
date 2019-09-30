#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;

int a[maxn];
bool mark[maxn];

bool ok (int x) {
    while (x % 2 == 0)
        x /= 2;
    while (x % 3 == 0)
        x /= 3;
    return (x == 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    int N = 30000;
    int n;
    cin >> n;
    if (n == 3) {
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }
  cout << 2 << " " << 3 << " " << 4 << " " << 9 << " ";
    n -= 4;
    for (int i = 4; n > 1 and 2 * i + 2 <= N; i += 3) {
      cout << i * 2 << " " << 2 * i + 2 << " ";
        n -= 2;
    }
    for (int i = 5; n > 1 and 3 * i <= N; i += 4) {
      cout << 3 * i << " " << 3 * i + 6 << " ";
        n -= 2;
    }
    for (int i = 6; n > 0 and i <= N; i += 6) {
      cout << i << " ";
        n --;
    }
    cout << endl;
}