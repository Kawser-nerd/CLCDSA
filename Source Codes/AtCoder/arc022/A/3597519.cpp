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

    string s;
    cin >> s;
    int i=0,n=s.size();
    while(s[i]!='i'&&s[i]!='I'){
        i++;
        if(n==i){
            cout << "NO" << endl;
            return 0;
        }
    }

    while(s[i]!='c'&&s[i]!='C'){
        i++;
        if(n==i){
            cout << "NO" << endl;
            return 0;
        }
    }
    while(s[i]!='t'&&s[i]!='T'){
        i++;
        if(n==i){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}