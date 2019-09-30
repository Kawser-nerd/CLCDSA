#include<vector>
#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n, k;

int sum[N], mins[N], maxs[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n - k + 1; ++i) {
            scanf("%d", sum + i);
        }
        vector<vector<int> > deltas;
        for (int i = 0; i < k; ++i) {
            vector<int> seq;
            seq.push_back(0);
            for (int j = i; j + 1 < n - k + 1; j += k) {
                seq.push_back(seq.back() + sum[j + 1] - sum[j]); 
            }
            deltas.push_back(seq);
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            mins[i] = INT_MAX;
            maxs[i] = INT_MIN;
            for (int j = 0; j < (int)deltas[i].size(); ++j) {
                //printf("%d ", deltas[i][j]);
                mins[i] = min(mins[i], deltas[i][j]);
                maxs[i] = max(maxs[i], deltas[i][j]);
            }
            ans = max(ans, (maxs[i] - mins[i]));
            //printf("\n");
        }
        int left = sum[0];
        for (int i = 0; i < k; ++i) {
            left -= -mins[i];
        }
        left %= k;
        if (left < 0) {
            left += k;
        }
        for (int i = 0; i < k; ++i) {
            left -= ans - (maxs[i] - mins[i]);
        }
        if (left > 0) {
            ++ans;
        }
        static int id = 0;
        printf("Case #%d: %d\n", ++id, ans);
    }
    return 0;
}
