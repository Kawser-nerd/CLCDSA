#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int res=0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '1'){
            res ++;
        }
    }
    cout << res << endl;
}