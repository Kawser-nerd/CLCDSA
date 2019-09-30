#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

long long calc() {
    string s;
    getline(cin, s);
    map<char, long long> m;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]] = -1;
    }
    long long res = 0;
    long long base = m.size();
    if (base < 2) base = 2;
    
    vector<bool> used(base + 1, false);
    int iNow = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (m[s[i]] == -1) {
            if (i == 0) {
               m[s[i]] = 1;
               used[1] = true;
            }
            else {
               while (used[iNow] == true) iNow++;
               m[s[i]] = iNow;
               used[iNow] = true;   
            }
        }
        res = res * base + m[s[i]];
    }
    return res;
}

int main() {
    int T;
    cin >> T >> ws;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << calc() << endl;
    }
}
