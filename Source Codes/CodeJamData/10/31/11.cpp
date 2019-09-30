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

int tt, n, a[10000], b[10000];
int main()
    {
        freopen("A-large.in", "r", stdin);
        freopen("A-large.out", "w", stdout);
   //     freopen("in.txt", "r", stdin);
 //       freopen("out.txt", "w", stdout);
        cin >> tt;
        for (int ca = 1; ca <= tt; ca++)
            {
                cin >> n;
                for (int i = 0; i < n; i++)
                    scanf("%d %d", &a[i], &b[i]);
                
                for (int i = 0; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                        if (a[i] > a[j])
                            {
                                swap(a[i], a[j]);
                                swap(b[i], b[j]);
                            }
                int ans = 0;
                for (int i = 0; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                        if (b[i] > b[j])
                            ans++;
                printf("Case #%d: %d\n", ca, ans);
            }
    }
