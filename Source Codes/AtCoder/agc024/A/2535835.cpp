#include <iostream>
#include <vector>
#include <string>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int main(){

    vector<long long int> v(3),w(3);
    REP(i,3){cin >> v[i];}

    
    long long int n;
    cin >> n;
    cout << (v[0] - v[1]) * ((n%2)*(-1)+((n%2)==0)) << endl;
    return 0;
}