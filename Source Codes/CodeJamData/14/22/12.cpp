#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int casenum = 1; casenum <= T; casenum++){
        printf("Case #%d: ", casenum);
        int A, B, C;
        cin >> A >> B >> C;
        long long dp[2][2][2] = {};

        dp[0][0][0] = 1;

        for(int i = 31; i >= 0; i--){
            long long next[2][2][2] = {};
            int x = A >> i & 1;
            int y = B >> i & 1;
            int z = C >> i & 1;

            // printf("i = %d\n", i);
            for(int la = 0; la < 2; la++)
            for(int lb = 0; lb < 2; lb++)
            for(int lc = 0; lc < 2; lc++)
            for(int a = 0; a < 2; a++)
            for(int b = 0; b < 2; b++){
                int c = a & b;
                if(!la && a > x) continue;
                if(!lb && b > y) continue;
                if(!lc && c > z) continue;
                int nla = la || (a < x);
                int nlb = lb || (b < y);
                int nlc = lc || (c < z);
                // if(dp[la][lb][lc] > 0)
                // printf("next[%d][%d][%d] <- dp[%d][%d][%d]\n", nla, nlb, nlc, la, lb, lc);
                next[nla][nlb][nlc] += dp[la][lb][lc];
            }

            for(int la = 0; la < 2; la++)
            for(int lb = 0; lb < 2; lb++)
            for(int lc = 0; lc < 2; lc++){
                // printf("next[%d][%d][%d] = %lld\n", la, lb, lc, next[la][lb][lc]);
            }

            memcpy(dp, next, sizeof(dp));
        }

        long long ans = dp[1][1][1];
        cout << ans << endl;

    }
    return 0;
}

