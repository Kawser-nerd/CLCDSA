#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    long long int w,n,k;
    cin>>w>>n>>k;
    vector<pair<long long int,long long int>> v(n);
    REP(i,n){
        scanf("%lld %lld",&v[i].first,&v[i].second);
    }
    vector<vector<vector<long long int>>> dp(n+1,vector<vector<long long int>>(w + 1, vector<long long int>(k + 1, 0)));


    REP(i,n){
        FOR(j,1,w+1){
            FOR(l,1,k+1){

                if(j>=v[i].first){
                    dp[i + 1][j][l] = max(max(dp[i+1][j-1][l],dp[i+1][j][l-1]),max(dp[i][j][l], v[i].second+dp[i][j - v[i].first][l - 1]));
                }else{
                    dp[i + 1][j][l] = max(max(dp[i + 1][j - 1][l], dp[i + 1][j][l - 1]), dp[i][j][l]);
                }

            }
        }

    }


    cout << dp[n][w][k] << endl;

    return 0;
}