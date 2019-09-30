#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

const int size = 100;
int n;
int cnt[size];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> cnt[i];

        cout << "Case #" << tnum + 1 << ":";

        vector <pair <int, int> > parties;
        for (int i = 0; i < n; i++)
            parties.pb(mp(cnt[i], i));

        while (true) {
            sort(parties.rbegin(), parties.rend());
            while (!parties.empty() && parties.back().fs == 0)
                parties.pop_back();
            if (parties.empty())
                break;

            if (parties.size() != 2u) {
                cout << ' ' << char('A' + parties[0].sc);
                parties[0].fs--;
            } else {
                cout << ' ' << char('A' + parties[0].sc) << char('A' + parties[1].sc);
                parties[0].fs--;
                parties[1].fs--;
            }            

        }

        cout << endl;
    }

    return 0;
}