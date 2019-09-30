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
    string s, t;
    cin >> s >> t;
    int n=s.size();
    vector<int> s_letter_num(26,0), t_letter_num(26,0);
    REP(i,n){
        s_letter_num[s[i] - 'a']++;
        t_letter_num[t[i] - 'a']++;
    }
    sort(s_letter_num.begin(), s_letter_num.end());
    sort(t_letter_num.begin(), t_letter_num.end());
    REP(i,26){
        if(s_letter_num[i]!=t_letter_num[i]){
            cout << "No" << endl;
        return 0;
        }
        
    }
    cout << "Yes" << endl;
    return 0;
}