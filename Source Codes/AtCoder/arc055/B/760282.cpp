#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<utility>   
#include<math.h>
#include<algorithm>
using namespace std;

typedef pair<int,int> P;

//n????????k???????????N????????
//???????
//???????
//??????????????????????????
double dp[1010][1010][2];

int main()
{
    // get a integer
    int N, K, i, j, k;
    cin >> N >> K;

    for (i = 0; i < N+1; ++i) {
        for (j = 0; j < K+2; ++j) {
            for (k = 0; k < 2; ++k) {
                dp[i][j][k] = 0.0;
            }
        }
    }

    for (j = 0; j < K+1; ++j) {
        dp[N][j][1] = 1.0;//ate max
        dp[N][j][0] = 0.0;//didn't eat max
    }

    for (i = N - 1; i >= 0; --i) {
        for (j = 0; j < K+1; ++j) {
            for (k = 0; k < 2; ++k) {
                double P = 1.0 / ( i + 1 );
                double tmp = ( 1.0 - P ) * dp[i+1][j][k]
                    + P * max(dp[i+1][j+1][1],dp[i+1][j][0]);
                dp[i][j][k] = tmp;
                /* cout << i << "," << j << "," << k << " : " <<  dp[i][j][k] << endl; */
            }
        }
    }

    printf( "%.9f\n", dp[0][0][1] );
}