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
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;

int main(){

    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> v(m+1,0);
    int l, r, s,result=0;
    REP(i,n){
        scanf("%d%d%d", &l, &r, &s);
        v[l - 1] += s;
        v[r] -= s;
        result += s;

    }
    int mini = inf;
    FOR(i,1,m+1){
        v[i] += v[i - 1];
        mini = min(mini, v[i - 1]);
    }
    
        cout << result-mini << endl;
    
    return 0;
}