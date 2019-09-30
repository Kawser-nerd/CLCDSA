#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int i, j, s_len = s.size(), t_len = t.size();
    for(i=s_len-1; i>=0; i--) {
        if(s[i] == '?' || s[i] == t[0]) {
            for(j=0; j<t_len && i+j<s_len; j++) {
                if(s[i+j] != '?' && s[i+j] != t[j]) break;
                if(j == t_len-1) {
                    for(j=0; j<t_len; j++) s[i+j] = t[j];
                    for(j=0; j<s_len; j++) if(s[j] == '?') s[j] = 'a';
                    cout << s << endl;
                    return 0;
                }
            }
        }
    }
    cout << "UNRESTORABLE" << endl;
}