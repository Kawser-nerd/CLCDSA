#include <iostream>
#include <string>

using namespace std;

int main(){
    string S;
    cin >> S;
    int c[100000];
    int c_max;
    int c_prev;
    for(int i = 0; i < 26; i++){
        //cout << char('a'+i)<< endl;
        if(S[0] - 'a' == i) c[0] = -1;
        else c[0] = 1;
        if(S[1] - 'a' == i) c[1] = c[0]-1;
        else c[1] = c[0]+1;
        if(c[1] < 0){
            cout << 1 << ' ' << 2 << endl;
            return 0;
        }
        c_max = c[0];
        int max_idx = 0;
        c_prev = c[1];
        for(int j = 2; j < S.size(); j++){
            if(S[j] - 'a' == i) c[j] = c[j-1]-1;
            else c[j] = c[j-1]+1;
            if(c[j] < 0) {
                cout << 1 <<  ' ' << j+1 << endl;
                return 0;
            }
            if(c[j] - c_max < 0) {
                cout << max_idx+2 <<  ' ' << j+1 << endl;
                return 0;
            } 
            if(c_max < c_prev){
                c_max = c_prev;
                max_idx = j-1;
            }
            c_prev = c[j];
        }
    }
    cout << -1 <<  ' ' << -1 << endl;
}