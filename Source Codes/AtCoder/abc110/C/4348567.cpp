#include <iostream>
#include <limits.h>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void){
    string s, t, ans1, ans2;
    cin >> s;
    cin >> t;
    
    int rst = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            string a, b;
            a[0] = s[i], b[0] = t[i];
            for (int j = 0; j < t.size(); j++) {
                if (s[j] == a[0]) s[j] = b[0];
                else if (s[j] == b[0]) s[j] = a[0];
            }
            rst++;
        }
        if (rst > 26) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    if (s == t) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    //cout << s << endl << t << endl;
    
}