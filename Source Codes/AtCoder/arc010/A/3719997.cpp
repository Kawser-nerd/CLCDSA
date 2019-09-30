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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int tmp;
    if(n<=a){
        n += b;
    }
    REP(i,m){
        cin >> tmp;
        n -= tmp;
        if(n<0){
            cout << i + 1 << endl;
            return 0;
        }else if(n<=a){
            n += b;
        }
        
    }
    cout << "complete" << endl;

    return 0;
}