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

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> youbou(m); 
    REP(i,m){
        cin>>youbou[i].second>>youbou[i].first;
    }
    sort(youbou.begin(), youbou.end());

    vector<int> cut;
    int result = 1;
    cut.push_back(youbou[0].first - 1);

    FOR(i,1,m){

        for(auto x:cut){
            if(youbou[i].second<=x&&x<youbou[i].first){
                goto END;
            }
        }

        result++;
        cut.push_back(youbou[i].first - 1);

    END:;

    }
    cout << result << endl;

    return 0;
}