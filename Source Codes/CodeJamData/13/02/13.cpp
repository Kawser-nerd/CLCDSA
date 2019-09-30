//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>

using namespace std;

typedef long long L;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("large.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        bool possible = true;

        int n, m;
        cin >> n >> m;
        vector< vector<int> > lawn(n, vector<int>(m));

        for (int i = 0; i != lawn.size(); ++i) {
            for (int j = 0; j != lawn[i].size(); ++j)
                cin >> lawn[i][j];
        }


        for (int i = 0; i != lawn.size() && possible; ++i) {
            for (int j = 0; j != lawn[i].size() && possible; ++j) {
                int h = lawn[i][j];
                int k;
                for (k = 0; k != lawn[i].size(); ++k) {
                    if (lawn[i][k] > h)
                        break;
                }
                if (k == lawn[i].size())
                    continue;
                for (k = 0; k != lawn.size(); ++k) {
                    if (lawn[k][j] > h)
                        break;
                }

                if (k != lawn.size())
                    possible = false;
            }
        }

        cout << "Case #" << cas << ": ";
        cout << (possible ? "YES" : "NO");
        cout << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}

