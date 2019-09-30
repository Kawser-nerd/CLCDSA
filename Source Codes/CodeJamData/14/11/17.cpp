#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main(int argc, char* argv[])
{
    int tt;
    cin >> tt;

    forn(tx, tt)
    {
        int n, l;
        cin >> n >> l;

        vector<string> a(n), b(n);
        forn(i, n)
            cin >> a[i];
        forn(i, n)
            cin >> b[i];

        set<string> bb(b.begin(), b.end());
        assert(int(bb.size()) == n);

        int result = INT_MAX;

        forn(i, n)
        {
            vector<bool> flip(l);
            forn(j, l)
                flip[j] = (a[0][j] != b[i][j]);
            set<string> aa;
            forn(j, n)
            {
                string r = a[j];
                forn(t, l)
                    r[t] = char(r[t] ^ flip[t]);
                aa.insert(r);
            }
            if (aa == bb)
            {
                int cnt = 0;
                forn(j, l)
                    cnt += flip[j];
                result = min(result, cnt);
            }
        }

        cout << "Case #" << (tx + 1) << ": ";
        if (result == INT_MAX)
            cout << "NOT POSSIBLE";
        else
            cout << result;
        cout << endl;
    }
}
