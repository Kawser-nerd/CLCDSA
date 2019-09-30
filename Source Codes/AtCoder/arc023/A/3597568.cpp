#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    constexpr int end_day = 365 * 2014 + (2014 / 4) - (2014 / 100) + (2014 / 400) + ((306 * (5 + 1)) / 10) + 17 - 429;
    int y, m, d;
    cin >> y >> m >> d;
    if(m<3){
        m+=12;
        y--;
    }
    cout << end_day - (365 * y + (y / 4) - (y / 100) + (y / 400) + ((306 * (m + 1)) / 10) + d - 429)<<endl;
    return 0;
}