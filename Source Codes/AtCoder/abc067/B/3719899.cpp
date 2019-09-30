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

    int a,b;
    cin >> a >> b;
    vector<int> v(a);
    REP(i,a){cin >> v[i];}
    sort(v.begin(), v.end());
    int result=0;
    a--;
    REP(i,b){
        result += v[a - i];
    }
    cout << result << endl;
    return 0;
}