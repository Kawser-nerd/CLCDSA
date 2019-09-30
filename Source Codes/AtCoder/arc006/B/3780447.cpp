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

    int n,l;
    cin >> n >> l;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    cin.ignore();
    vector<string> s(l);
    
    REP(i,l){
        getline(cin, s[i]);
    }
    
    string maru;
    getline(cin, maru);
    int nowline = maru.find('o');
    while(l--){
    
        if((nowline!=n*2)&&s[l][nowline+1]=='-'){
            nowline += 2;
        }else if(nowline!=0&&s[l][nowline-1]=='-'){
            nowline -= 2;
        }

    }
    cout << (nowline + 2) / 2 << endl;
    return 0;
}