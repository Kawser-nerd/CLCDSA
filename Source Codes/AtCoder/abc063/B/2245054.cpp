#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool s_let = false;
    for (int i = 0; i < s.size()-1; ++i){
        for (int j = i + 1; j < s.size(); ++j){
            if (s[i]==s[j]){
                s_let = true;
                break;
            }
        }
    }
    if (s_let) cout << "no" << endl;
    else cout << "yes" << endl;
}