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

typedef unsigned char Key;

typedef multiset<Key> Keys;

struct Chest
{
    Key opening;
    vector<Key> contained;

    void read()
    {
        int op, n;
        cin >> op >> n;
        opening = op;
        contained.resize(n);
        for (int i = 0; i != n; ++i) {
            int k;
            cin >> k;
            contained[i] = k;
        }
    }
};

vector<Chest> chests;
vector<char> used;

vector<int> answer;

bool checkChests(int left, const Keys & qqq) // may change used only!
{
    Keys keys = qqq;
    Keys unused = keys;

    vector<Key> missing;

    int prevLeft = -1;
    while (left != 0 && left != prevLeft) {
        prevLeft = left;

        for (int i = 0; i != chests.size(); ++i) {
            const Key cur = chests[i].opening;
            if (! used[i] && keys.count(cur) != 0) {
                used[i] = true;
                --left;
                keys.insert(chests[i].contained.begin(),
                            chests[i].contained.end());
                unused.insert(chests[i].contained.begin(),
                              chests[i].contained.end());

                Keys::iterator it = unused.find(cur);
                if (it == unused.end())
                    missing.push_back(cur);
                else
                    unused.erase(it);
            }
        }
    }

    if (left != 0)
        return false;

    for (int i = 0; i != missing.size(); ++i) {
        Keys::iterator it = unused.find(missing[i]);
        if (it == unused.end())
            return false;
        unused.erase(it);
    }

    return true;
}


bool openChests(int left, Keys & keys)
{
    if (left == 0)
        return true;
    --left;

    for (size_t i = 0; i != chests.size(); ++i) {
        Keys::iterator it;
        if (! used[i] && (it = keys.find(chests[i].opening)) != keys.end())
        {
            used[i] = true;
            keys.erase(it);

            {
                Keys next = keys;
                next.insert(chests[i].contained.begin(),
                            chests[i].contained.end());

                const vector<char> backup = used;
                bool possible = checkChests(left, next);
                used = backup;

                if (possible && openChests(left, next)) {
                    answer[left] = i + 1;
                    return true;
                }
            }


            keys.insert(chests[i].opening);
            used[i] = false;
        }
    }

    return false;
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
        int nKeys, nChests;
        cin >> nKeys >> nChests;
        Keys keys;
        for (int i = 0; i != nKeys; ++i) {
            int k;
            cin >> k;
            keys.insert(k);
        }

        chests.assign(nChests, Chest());
        for (int i = 0; i != chests.size(); ++i)
            chests[i].read();
        used.assign(nChests, false);
        answer.resize(nChests);

        bool possible = checkChests(nChests, keys);

        if (possible) {
            for (int i = 0; i != chests.size(); ++i)
                used[i] = false;
            possible = openChests(nChests, keys);
        }

        cout << "Case #" << cas << ':';

        if (possible) {
            for (int i = answer.size() - 1; i >= 0; --i)
                cout << ' ' << answer[i];
        }
        else
            cout << " IMPOSSIBLE";

        cout << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}

