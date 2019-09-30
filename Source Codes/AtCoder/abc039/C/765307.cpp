// ????
// http://abc039.contest.atcoder.jp/tasks/abc039_c
#include <iostream>

using namespace std;

int main()
{
    char ans[2];
    char S[20];
    cin >> S;

    if(S[1]=='W'){
        if(S[6]=='W')
            strcpy(ans,"Si");
        else
            strcpy(ans,"Mi");
    }else{
        if(S[3]=='W'){
            if(S[8]=='W')
                strcpy(ans,"La");
            else
                strcpy(ans,"Re");
        }else if(S[5]=='B'){
            strcpy(ans,"Fa");
        }else{
            if(S[10]=='W')
                strcpy(ans,"So");
            else
                strcpy(ans,"Do");
        }
    }

    cout << ans;
    return 0;
}