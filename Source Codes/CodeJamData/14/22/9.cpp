#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int INF = 1000000000;
const int MOD = 1000000007;

Int dp[50][2][2][2];

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int t;
    cin >> t;
    FOR(ttt,0,t)
    {
        FILL(dp,0);
        printf("Case #%d: " , ttt + 1);
        int a , b , c;
        cin >> a >> b >> c;
        vector<int> A , B , C;
        FOR(i,0,32)
        {
            A.push_back(a % 2);
            a /= 2;
            B.push_back(b % 2);
            b /= 2;
            C.push_back(c % 2);
            c /= 2;
        }
        reverse(ALL(A));
        reverse(ALL(B));
        reverse(ALL(C));

        //FOR(i,0,32)
        //{
        //    cout << A[i] << B[i] << C[i] << endl;
        //}

        dp[0][0][0][0] = 1;
        FOR(i,0,32)
            FOR(qa,0,2)
                FOR(qb,0,2)
                    FOR(qc,0,2)
                    {
                        if (dp[i][qa][qb][qc])
                        {
                            FOR(aa,0,2)
                                FOR(bb,0,2)
                                {
                                    int cc = (aa & bb);
                                    if ( (aa > A[i] && !qa) || (bb > B[i] && !qb) || (cc > C[i] && !qc))
                                        continue;
                                    int nqa = qa;
                                    if (aa < A[i])
                                        nqa = 1;
                                    int nqb = qb;
                                    if (bb < B[i])
                                        nqb = 1;
                                    int nqc = qc;
                                    if (cc < C[i])
                                        nqc = 1;

                                    //printf("%d %d %d %d %d %d %d %d %d\n" , i , qa,qb,qc,nqa,nqb,nqc,aa,bb);

                                    dp[i + 1][nqa][nqb][nqc] += dp[i][qa][qb][qc];
                                }
                        }
                    }
        cout << dp[32][1][1][1] << endl;

    }

    return 0;
}

