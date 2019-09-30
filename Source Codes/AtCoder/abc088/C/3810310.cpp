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

    vector<vector<int>> c(3,vector<int>(3));
    REP(i,3){
        REP(j,3){
            cin >> c[i][j];
        }
    }

    vector<int> a(3);
    for(a[0] = 0; a[0] <= c[0][0];a[0]++){
        for(a[1] = 0; a[1] <= c[1][0];a[1]++){
            for(a[2] = 0; a[2] <= c[2][0];a[2]++){
                if(c[0][0]-a[0]==c[1][0]-a[1]&&c[2][0]-a[2]==c[1][0]-a[1]){
                    if(c[0][1]-a[0]==c[1][1]-a[1]&&c[2][1]-a[2]==c[1][1]-a[1]){
                        if(c[0][2]-a[0]==c[1][2]-a[1]&&c[2][2]-a[2]==c[1][2]-a[1]){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}