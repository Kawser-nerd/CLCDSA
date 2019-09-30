#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    cout << min(min(min(x, y) * 2 * c + (max(x, y) - min(x, y)) * (x >= y ? a : b), max(x, y) * 2 * c), a * x + b * y) << endl;

    return 0;
}