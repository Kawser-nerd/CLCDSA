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
    int n, m;
    cin >> n >> m;
    m--;
    int k = m, tmp_pre,tmp_now,result = 0;
    cin >> tmp_pre;
    if(m==0){
        cout << n << endl;
        return 0;
    }
    n--;
    REP(i,n){
        cin >> tmp_now;
        if(tmp_pre<tmp_now){
            k--;
        }else{
            k = m;
        }
        if(k<=0){
            result++;

        }
        tmp_pre = tmp_now;
    }
    cout << result << endl;
    return 0;
}