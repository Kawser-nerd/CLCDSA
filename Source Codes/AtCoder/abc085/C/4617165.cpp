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

    int n,y;
    cin>>n>>y;
    int k;
    REP(i,n+1){
        REP(j,n-i+1){
            k = n - i - j;
            if(y==10000*i+5000*j+1000*k){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;


    return 0;
}