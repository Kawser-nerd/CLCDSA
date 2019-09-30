#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int main(){

    int n;
    cin >> n;

    unordered_map<string,int> shiritori_log;
    char last_letter;
    string tmp;
    REP(i,n){
        cin >> tmp;
        if(i>0&&last_letter!=tmp[0]){
            cout << "No" << endl;
            return 0;
        }
        shiritori_log[tmp]++;
        if(shiritori_log[tmp]>1){
            cout << "No" << endl;
            return 0;
        }
        last_letter = tmp[tmp.size() - 1];

    }

    cout << "Yes" << endl;

    return 0;
}