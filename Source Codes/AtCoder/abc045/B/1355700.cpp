#include <iostream>
using namespace std;

int main(){
    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    int base = 0;
    char ans, c;
    while(1){
        if(s[base].size()==0){
            ans = c;
            break;
        }
        c = s[base][0];
        s[base].erase(s[base].begin());
        base = c - 'a';
    }

    cout << (char)(ans - ('a' - 'A')) << endl;

    return 0;
}