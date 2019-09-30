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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>

#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define FST first
#define SND second
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int MOD = 1000000007;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;

signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);

    int aI,aO,aT,aJ,aL,aS,aZ;
    cin >> aI >> aO >> aT >> aJ >> aL >> aS >> aZ;

    int ans0 = 0;
    ans0 += aO;
    ans0 += aJ/2*2;
    ans0 += aL/2*2;
    ans0 += aI/2*2;

    int ans1 = 0;
    ans1 += aO;
    if(aI>0 && aL>0 && aJ>0){
        ans1 += 3;
        aI--;
        aL--;
        aJ--;
    }
    ans1 += aJ/2*2;
    ans1 += aL/2*2;
    ans1 += aI/2*2;

    cout << max(ans1,ans0) << endl;
    
    return 0;
}