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

    int n,l;
    cin>>n>>l;
    vector<string> v(n);
    REP(i,n){
        cin >> v[i];
    }

    sort(v.begin(),v.end());
    REP(i,n){
        cout << v[i];
    }
    cout << endl;
    return 0;
}