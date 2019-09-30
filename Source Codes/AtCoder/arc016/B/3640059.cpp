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

    int n;
    cin >> n;
    vector<bool> condition(9,0);
    string tmp;
    int j = 0,result=0;
    REP(i,n){
        cin >> tmp;
        for (j = 0; j < 9;j++){
            if(tmp[j]=='o'&&condition[j]==0){
                condition[j] = 1;
                result++;
            }else if(tmp[j]=='x'){
                result++;
                condition[j] = 0;
            }else if(tmp[j]=='.'&&condition[j]==1){
                condition[j] = 0;
            }
        }
    }
    cout << result << endl;
    return 0;
}