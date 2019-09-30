#include <iostream>
using namespace std;

int main(){
    string s[12];
    int ans = 0;
    for(int i = 0; i < 12; ++i){ cin >> s[i]; }
    for(int i = 0; i < 12; ++i){
        for(int j = 0; j < s[i].length(); ++j){
            if(s[i][j] == 'r'){
                ++ans;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}