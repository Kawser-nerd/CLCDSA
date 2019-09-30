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

    int d, g;
    cin >> d >> g;

    vector<pair<long long int,long long int>> v(d);
    REP(i,d){
        scanf("%lld %lld", &v[i].first, &v[i].second);
    }

    long long int tmp_score,tmp_result, result = linf,max_hanpa=0;

    for (long long int bit = (long long int)pow(2, d) - 1; bit >= 0;bit--){
        tmp_score = 0;
        tmp_result = 0;

        REP(i,d){
            if(bit&(long long int)pow(2,i)){
                tmp_score += (i+1) * 100 * v[i].first + v[i].second;
                tmp_result += v[i].first;
            }else{
                max_hanpa = i;
            }
        }
        if(tmp_score<g){
            if(g-tmp_score < v[max_hanpa].first*(max_hanpa+1)*100){
                tmp_result += (g - tmp_score+(max_hanpa+1)*100-1) / ((max_hanpa+1) * 100);
            }else{
                continue;
            }
        }

        result = min(result, tmp_result);
    }

    cout << result << endl;
    return 0;
}