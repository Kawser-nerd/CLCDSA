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
    int l, m, n;
    cin >> l >> m >> n;
    int result = n,stock=n;
    while(stock>=l){
        
        result += m*(stock/l);
        stock = stock%l+m*(stock/l);

    }
    cout << result << endl;
    return 0;
}