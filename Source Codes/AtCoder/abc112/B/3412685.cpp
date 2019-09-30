#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int main(){

    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> v(n);
    REP(i,n){
        cin >> v[i].first >> v[i].second;
    }

    int result=65535;

    REP(i,n){
        if(v[i].second<=t){
            result = min(result, v[i].first);
        }
    }

    if(result==65535){
        cout << "TLE" << endl;
    }else{
        cout << result << endl;
    }

    return 0;
}