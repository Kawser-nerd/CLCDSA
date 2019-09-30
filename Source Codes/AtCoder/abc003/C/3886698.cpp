#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <iomanip>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n,k;
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    REP(i,n){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    double result = 0;
    REP(i,k){
        result = (result + 1. * v[n - k + i]) / 2.0;
    }
    printf("%.7lf\n", result);
    return 0;
}