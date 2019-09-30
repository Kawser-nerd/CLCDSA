#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <bitset>

#define INF 1000000000
#define Inf 1000000000000000000
#define mp make_pair
#define pb push_back
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int c[30], idx, sz;
ll ans;
char s[200010];

int main() {
    //freopen("in","r",stdin);
    
    scanf("%s", s);
    
    ans = 1;
    
    sz = strlen(s);

    for(int i = 0; i < sz; ++i) {
        idx = s[i] - 'a';
        ans += (i - c[idx]);
        ++c[idx];
    }
    
    printf("%lld", ans);

    return 0;
}