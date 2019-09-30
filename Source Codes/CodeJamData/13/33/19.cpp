#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("large.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

struct Event {
    Event(int time_, int left_, int right_, int height_, int repair_):
        time(time_), left(left_), right(right_), height(height_), repair(repair_)
    { }

    int time;
    int left;
    int right;
    int height;
    bool repair;
};

bool operator < (const Event& a, const Event& b) {
    if (a.time != b.time) {
        return a.time < b.time;
    }
    return a.repair > b.repair;
}

const int INF = 1000000000;

struct Tree
{
    Tree(int size_):
        size(size_),
        mas(4 * size + 10, 0),
        s(4 * size + 10, false)
    { }

    void set(int left, int right, int l, int r, int val, int ind) {
        if (left <= l && r <= right) {
            s[ind] = true;
            //mas[ind] = val;
            mas[ind] = max(mas[ind], val);
            return;
        }
        if (left >= r || right <= l) {
            return;
        }
        int m = (l + r) / 2;
        
        s[ind] = false;
        set(l, m, l, m, mas[ind], ind * 2);
        set(m, r, m, r, mas[ind], ind * 2 + 1);
        
        set(left, right, l, m, val, ind * 2);
        set(left, right, m, r, val, ind * 2 + 1);
        mas[ind] = min(mas[ind * 2], mas[ind * 2 + 1]);
    }
    
    int get(int left, int right, int l, int r, int ind) {
        if (left <= l && r <= right) {
            //cerr << "TREE " << l << " " << r << " " << mas[ind] << endl;
            return mas[ind];
        }
        if (left >= r || right <= l) {
            return INF;
        }
        int m = (l + r) / 2;
        if (s[ind]) {
            s[ind] = false;
            set(l, m, l, m, mas[ind], ind * 2);
            set(m, r, m, r, mas[ind], ind * 2 + 1);
        }
        return min(get(left, right, l, m, ind * 2), get(left, right, m, r, ind * 2 + 1));
    }


    int getMin(int left, int right)
    {
        return get(left, right, 0, size, 1);
    }

    void setMin(int left, int right, int value) {
        set(left, right, 0, size, value, 1);
    }

    int size;
    vector<int> mas;
    vector<bool> s;
};


struct Tree2
{
    Tree2(int size_):
        mas(size_)
    { }

    int getMin(int left, int right)
    {
        int res = INF;
        for (int i = left; i < right; ++i) {
            res = min(res, mas[i]);
        }
        return res;
    }

    void setMin(int left, int right, int value) {
        for (int i = left; i < right; ++i) {
            mas[i] = max(value, mas[i]);
        }
    }

    vector<int> mas;
};



int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cerr << tt << endl;
        int n;
        cin >> n;
        vector<Event> events;
        for (int i = 0; i < n; ++i) {
            int d, count, w, e, s, delta, shift, sIncr;
            cin >> d >> count >> w >> e >> s >> delta >> shift >> sIncr;
            for (int i = 0; i < count; ++i) {
                events.pb(Event(d, w, e, s, false));
                events.pb(Event(d + 1, w, e, s, true));
                d += delta;
                w += shift;
                e += shift;
                s += sIncr;
            }
        }

        // Compress coordinates
        vector<int> coord;
        for (int i = 0; i < events.size(); ++i) {
            coord.pb(events[i].left);
            coord.pb(events[i].right);
        }
        sort(all(coord));

        map<int, int> comp;
        for (int i = 0; i < coord.size(); ++i) {
            comp[coord[i]] = i;
        }

        for (int i = 0; i < events.size(); ++i) {
            events[i].left = comp[events[i].left];
            events[i].right = comp[events[i].right];
        }

        Tree tree(coord.size());
        int res = 0;
        sort(all(events));
        for (int i = 0; i < events.size(); ++i) {
            if (events[i].repair) {
                tree.setMin(events[i].left, events[i].right + 1, events[i].height);
            }
            else {
                int s = tree.getMin(events[i].left, events[i].right + 1);
                if (s < events[i].height) {
                    res += 1;
                }
            }
        }
        printf("Case #%d: %d\n", tt, res);
    }
    
    return 0;
}
