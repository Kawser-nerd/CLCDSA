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
    cin >> t >> s;
    int s_len = s.length(),t_len=t.length();
    int i, j;
    for (i = t_len - s_len; i >= 0;i--){
        for (j = 0; j < s_len;j++){
            if(t[i+j]!='?'&&s[j]!=t[i+j]){
                break;
            }
        }

        if(j==s_len){
            FOR(k,0,i){
                if(t[k]=='?'){
                    cout << 'a';
                }else{
                    cout << t[k];
                }
            }
            cout << s;
            FOR(k,i+s_len,t_len){
                if(t[k]=='?'){
                    cout << 'a';
                }else{
                    cout << t[k];
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
    return 0;
}