#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

long long dfs(vector<bool> open, vector<vector<bool>> &f, vector<vector<long long>> &p) {
    int n = f.size();
    if (open.size() == 10) {
        bool flag = false;
        for (int i = 0; i < open.size(); i++)
            if (open[i])
                flag = true;
        if (!flag)
            return -1000000000000000;
        
        vector<int> cnt(n, 0);
        for (int i = 0; i < 10; i++) {
            if (!open[i])
                continue;
            for (int j = 0; j < n; j++) {
                if (f[j][i])
                    cnt[j]++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += p[i][cnt[i]];

        return ans;
    }
    else {
        long long maxx = -1000000000;
        open.push_back(true);
        maxx = max(maxx, dfs(open, f, p));
        open.back() = false;
        maxx = max(maxx, dfs(open, f, p));

        return maxx;
    }
}




int main() {
    int n;
    cin >> n;
    vector<vector<bool>> f(n, vector<bool>(10, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            int tmp;
            cin >> tmp;
            f[i][j] = (tmp == 1);
        }
    }
    vector<vector<long long>> p(n, vector<long long>(11, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10; j++) {
            cin >> p[i][j];
        }
    }

    cout << dfs(vector<bool>(), f, p) << endl;

    return 0;
}