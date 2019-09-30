#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int solve()
{
    int n, len;
    cin >> n >> len;

    vector<long long> outlet(n), device(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<len; ++j){
            char c;
            cin >> c;
            outlet[i] <<= 1;
            outlet[i] |= c - '0';
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<len; ++j){
            char c;
            cin >> c;
            device[i] <<= 1;
            device[i] |= c - '0';
        }
    }

    int ret = INT_MAX;
    for(int i=0; i<n; ++i){
        vector<long long> a = outlet;
        vector<long long> b = device;

        long long x = a[0] ^ b[i];
        for(int j=0; j<n; ++j)
            b[j] = b[j] ^ x;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b){
            int cnt = 0;
            for(int j=0; j<len; ++j){
                if(x & 1)
                    ++ cnt;
                x >>= 1;
            }
            ret = min(ret, cnt);
        }
    }

    return ret;
}

int main()
{
    int T;
    cin >> T;

    for(int tc=1; tc<=T; ++tc){
        int ret = solve();
        if(ret == INT_MAX)
            cout << "Case #" << tc << ": NOT POSSIBLE" << endl;
        else
            cout << "Case #" << tc << ": " << ret << endl;
    }

    return 0;
}