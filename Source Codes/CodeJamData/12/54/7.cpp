#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

string S;
int K, N;
set<string> subs;
map<char, char> translate;

void initialize()
{
    for (char c = 'a'; c <= 'z'; c++)
        translate[c] = c;

    translate['o'] = '0';
    translate['i'] = '1';
    translate['e'] = '3';
    translate['a'] = '4';
    translate['s'] = '5';
    translate['t'] = '7';
    translate['b'] = '8';
    translate['g'] = '9';
}

string stringify(char a, char b)
{
    return string(1, a) + b;
}

void solve_case(int test_case)
{
    cin >> K >> S;
    N = S.length();
    subs.clear();

    for (int i = 0; i + 1 < N; i++)
    {
        char a = S[i], b = S[i + 1];
        char ta = translate[a], tb = translate[b];
        subs.insert(stringify(a, b));
        subs.insert(stringify(ta, b));
        subs.insert(stringify(a, tb));
        subs.insert(stringify(ta, tb));
    }

    map<char, int> counts;

    for (set<string>::iterator it = subs.begin(); it != subs.end(); it++)
    {
        counts[(*it)[0]]++;
        counts[(*it)[1]]--;
    }

    int total = subs.size(), diff = 0;

    for (map<char, int>::iterator it = counts.begin(); it != counts.end(); it++)
        diff += abs(it->second);

    printf("Case #%d: %d\n", test_case, total + max(diff / 2, 1));
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
