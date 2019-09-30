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

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> bs(m);
    REP(i,m){
        cin >> bs[i];
    }
    int tmpin,tmpsum=0,result=0;
    REP(i,n){
        REP(j,m){
            cin >> tmpin;
            tmpsum += tmpin * bs[j];
        }
        if(tmpsum>-c){
            result++;
        }

        tmpsum = 0;
    }

    cout << result << endl;

    return 0;
}