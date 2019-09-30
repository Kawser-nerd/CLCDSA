#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n;
    scanf("%d",&n);
    vector<pair<int, int>> ds(n);
    double result = 0;
    REP(i,n){
        scanf("%d %d\n", &ds[i].first, &ds[i].second);
    }
    
    REP(i,n-1){
        FOR(j,i+1,n){
            result=max(result,sqrt((double)(abs(ds[i].first-ds[j].first))*(double)(abs(ds[i].first-ds[j].first))+(double)(abs(ds[i].second-ds[j].second))*(double)(abs(ds[i].second-ds[j].second))));
        }
    }
    printf("%lf\n", result);
    return 0;
}