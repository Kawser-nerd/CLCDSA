#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int l = s.length();
    int lt = t.length();
    vector<char> str(l, '?');
    for (int i=0; i<l; ++i){
        if(s[i] != '?'){
            str[i] = s[i];
        }
    }
    bool key = false;
    for (int i=l-lt; i>=0; --i){
        if(key){break;}
        if(s[i] == t[0] || s[i] == '?'){
            bool key_insert = true;
            for (int j=0; j<lt; ++j){
                if(!(s[i+j] == t[j] || s[i+j] == '?')){
                    key_insert = false;
                    break;
                }
            }
            if(key_insert){
                for (int j=0; j<lt; ++j){
                    str[i+j] = t[j];
                }
                key = true;
            }
        }
    }
    if(!key){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    else {
        for (int i=0; i<l; ++i){
            if(str[i] == '?'){
                str[i] = 'a';
            }
        }
        for (int i=0; i<l; ++i){
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}