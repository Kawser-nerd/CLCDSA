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

    int n;
    cin >> n;
    vector<int> v(n);
    REP(i,n){
        scanf("%d", &v[i]);
    }
    int now_where = 1,pre_where,result=0;
    while(v[now_where-1]!=-1&&now_where!=2){
        pre_where = now_where;
        now_where=v[now_where-1];
        v[pre_where-1] = -1;
        result++;
    }
    cout << ((now_where == 2) ? result : -1) << endl;
    return 0;
}