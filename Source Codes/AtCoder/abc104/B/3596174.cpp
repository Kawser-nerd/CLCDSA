#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    cin >> S;

    bool AC = true;
    if('A' != S[0]){
        AC = false;
    }else{
        int C_cnt = 0;
        for(int i = 2; i < S.length() - 1; ++i){
            if('C' == S[i]){
                ++C_cnt;
                S[i] = 'c';
            }
        }
        AC = (C_cnt == 1);
        for(int i = 1; i < S.length(); ++i){
            if(('A' <= S[i]) && (S[i] <= 'Z')){
                AC = false;
                break;
            }
        }
    }

    if(AC) cout << "AC" << endl;
    else cout << "WA" << endl;

    return 0;
}