#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

#define PB push_back
#define MP make_pair

int tt;
long long L, P, C;
int main()
    {
        freopen("B-large.in", "r", stdin);
        freopen("B-large.out", "w", stdout);
//        freopen("in.txt", "r", stdin);
  //      freopen("out.txt", "w", stdout);
        cin >> tt;
        for (int ca = 1; ca <= tt; ca++)
            {
                cin >> L >> P >> C;
                int ans = 0;
                while (L < P)
                    {
                        L *= C;
                        ans++;
                    }
                int re = 0;
                while (ans > 1)
                    {
                        re++;
                        ans = (ans + 1) / 2;
                    }
                printf("Case #%d: %d\n", ca, re);
            }
    }
