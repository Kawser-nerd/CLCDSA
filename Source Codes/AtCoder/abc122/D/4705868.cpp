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

    int n;
    cin >> n;

    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,0))));
    REP(i,4){
        REP(j,4){
            REP(k,4){
                dp[3][i][j][k] = 1;
            }
        }
    }

    dp[3][0][2][1] = 0;
    dp[3][2][0][1] = 0;
    dp[3][0][1][2] = 0;

    REP(i,n){
        REP(j,4){
            REP(k,4){
                REP(l,4){
                    if(dp[i][j][k][l]==0){
                        continue;
                    }

                    
                    REP(m,4){

                        if((k==0&&l==2&&m==1)||(k==2&&l==0&&m==1)||(k==0&&l==1&&m==2)||(j==0&&l==2&&m==1)||(j==0&&k==2&&m==1)){
                            continue;
                        }else{
                            dp[i + 1][k][l][m] += dp[i][j][k][l];
                            dp[i + 1][k][l][m] %= mod;
                        }

                    }
                }
            }
        }
    }

    long long int result = 0;

    REP(i,4){
        REP(j,4){
            REP(k,4){

                result += dp[n][i][j][k];
                result %= mod;
            }
        }
    }


    cout << result << endl;

    return 0;
}