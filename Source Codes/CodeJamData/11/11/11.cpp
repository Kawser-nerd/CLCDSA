#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset((a),(b),sizeof(a))

#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const string name = "A-large";

int main() {
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
	int T;
	cin >> T;
	FOR (test, 1, T+1) {
        long long n;
        int pd, pg;
        cin >> n >> pd >> pg;
        cout << "Case #" << test << ": ";
        if (pg == 0 && pd != 0) {
            puts ("Broken");
            continue;
        } else
        if (pg == 100 && pd != 100) {
            puts ("Broken");
            continue;
        } 
        else {
            bool ok = false;
            FOR (i, 1, min(n, 100LL) + 1)
                if ((i * pd) % 100 == 0) {
                    ok = true;
                    break;
                }
            if (ok)
                puts("Possible");
            else
                puts("Broken");
        }            
    }
	return 0;
}
