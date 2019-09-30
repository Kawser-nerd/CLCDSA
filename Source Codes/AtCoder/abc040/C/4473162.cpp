#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
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
    vector<int> v(n);
    REP(i,n){scanf("%d",&v[i]);}
    
    vector<int> dp(n);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);

    FOR(i,2,n){
        dp[i]=min(dp[i-2]+abs(v[i]-v[i-2]),dp[i-1]+abs(v[i]-v[i-1]));
    }
    cout<<dp[n-1]<<endl;

    return 0;
}