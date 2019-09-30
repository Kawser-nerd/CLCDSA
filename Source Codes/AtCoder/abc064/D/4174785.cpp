#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int cnt = 0;
    int m = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == '(') cnt++;
        else cnt--;
        m = min(cnt, m);
    }

    if(m < 0){
        for(int i = 0; i < (-m); i++){
            cout << '(';
        }
        cnt += (-m);
    }
    cout << S;
    for(int i = 0; i < cnt; i++){
        cout << ')';
    }
    cout << endl;
}