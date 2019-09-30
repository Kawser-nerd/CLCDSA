#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int t,n;
    cin >>t>> n;
    
    array<int,101> tako={};
    int tmp;
    REP(i,n){
        cin >> tmp;
        tako[tmp]++;
    }
    int m;
    cin >> m;
    bool ok_flag;
    t++;
    REP(i,m){
        cin >> tmp;
        ok_flag = false;
        REP(j,t){
            if(tmp-t+j+1>=0){
                if(tako[tmp-t+j+1]){
                    tako[tmp - t + j+1]--;
                    ok_flag = true;
                    break;
                }
            }
        }
        if(!ok_flag){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}