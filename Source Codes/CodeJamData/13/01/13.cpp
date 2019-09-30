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

char lastCh;
bool same(char a, char b)
{
    lastCh = a == 'X' ? 0 : 1;
    return a != '.' && a == b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("large.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        vector<string> table(4);
        for (int i = 0; i != table.size(); ++i)
            cin >> table[i];
        int ans = 2;

        char * t = 0;
        for (int i = 0; i != table.size(); ++i) {
            for (int j = 0; j != table[i].size(); ++j) {
                if (table[i][j] == 'T')
                    t = & table[i][j];
            }
        }

        for (char c = 0; c <= 1; ++c) {
            if (t)
                *t = c == 0 ? 'X' : 'O';

            for (int i = 0; i != table.size() && ans == 2; ++i) {   // -
                int j;
                for (j = 1; j != table[i].size(); ++j) {
                    if (! same(table[i][j], table[i][0]))
                        break;
                }
                if (j == table[i].size())
                    ans = lastCh;
            }


            for (int j = 0; j != table[0].size() && ans == 2; ++j) {    //  |
                int i;
                for (i = 1; i != table.size(); ++i) {
                    if (! same(table[i][j], table[0][j]))
                        break;
                }
                if (i == table.size())
                    ans = lastCh;
            }

            if (ans == 2) {
                int i;
                for (i = 1; i != table.size(); ++i) {   //  \       *
                    if (! same(table[i][i], table[0][0]))
                        break;
                }

                if (i == table.size())
                    ans = lastCh;
                else {
                    for (i = 1; i != table.size(); ++i) { //    /
                        if (! same(table[i][table[i].size() - i - 1], table[0][table[0].size()-1]))
                            break;
                    }
                    if (i == table.size())
                        ans = lastCh;
                }
            }
        }

        if (ans == 2) {  // incomplete
            for (int i = 0; i != table.size(); ++i) {
                if (table[i].find('.') != string::npos) {
                    ans = 3;
                    break;
                }
            }
        }

        cout << "Case #" << cas << ": ";
        switch (ans) {
            case 0 :
                cout << "X won";
                break;
            case 1 :
                cout << "O won";
                break;
            case 2 :
                cout << "Draw";
                break;
            case 3 :
                cout << "Game has not completed";
                break;
            default :
                throw std::runtime_error("Wrong ans!");
        }
        cout << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}

