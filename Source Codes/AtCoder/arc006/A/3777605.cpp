#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <set>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int solve(){
    set<char> e;
    char tmp;
    REP(i,6){
        cin>>tmp;
        e.insert(tmp);
    }

    
    char b;
    cin>>b;

    vector<char> l(6);
    REP(i,6){
        cin >> l[i];
    }
    bool bonus_flag = false;
    int same_num = 0;
    auto it = e.begin();
    REP(i,6){
        it = e.find(l[i]);
        if(it!=e.end()){
            same_num++;
        }else if(l[i]==b){
            bonus_flag = true;
        }
    }
    
    if(same_num<=2){
        return 0;
    }else if(same_num==6){
        return 1;
    }else if(same_num==5){
        return 3 - (int)bonus_flag;
    }else{
        return 8 - same_num;
    }
}

int main(){

    cout << solve() << endl;


    return 0;
}