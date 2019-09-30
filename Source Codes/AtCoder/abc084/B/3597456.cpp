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

    int a, b;
    cin >> a >> b;
    char tmp;
    while(a--){
        cin>>tmp;
        if(tmp<'0'||'9'<tmp){
            cout << "No" << endl;
            return 0;
        }
    }

    cin >> tmp;
    if(tmp!='-'){
        cout << "No" << endl;
        return 0;
    }
    while(b--){
        cin>>tmp;
        if(tmp<'0'||'9'<tmp){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}