#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = s + '+';
    int ans {0};
    int count {0};
    
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            count++;
        }
        if (s[i] == '+') {
            if (count == 0) {
                ans++;
            }
            count = 0;
        }
    }
    cout << ans << endl;
    
    return 0;
}