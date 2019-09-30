#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str, t;
    cin >> str >> t;
    bool b1 = false;
    string unrest = "UNRESTORABLE";
    int n = str.length();
    int t_len = t.length();
    vector<char> s(n, '*');
    // insert t
    for(int i=n-t_len; i>=0; --i){
        if(b1){
            break;
        }
        for(int j=0; j<t_len; ++j){
            if(!(str[i+j] == '?' || str[i+j] == t[j])){
                break;
            }
            if(j == t_len - 1){
                for(int k=0; k<t_len; ++k){
                    s[i+k] = t[k];
                    b1 = true;
                }
            }
        }
    }
    if(b1){
        for(int i=0; i<n; ++i){
            if(str[i] != '?'){
                s[i] = str[i];
            }
        }
        for(int i=0; i<n; ++i){
            if(s[i] == '*'){
                s[i] = 'a';
            }
        }
        for(int i=0; i<n; ++i){
            cout << s[i];
        }
    }
    else {
        cout << unrest;
    }
    cout << endl;
}