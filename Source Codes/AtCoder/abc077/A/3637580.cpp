#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<char> c1(3), c2(3);
    string s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++) c1[i] = s1[i];
    for(int i = 0; i < s2.length(); i++) c2[i] = s2[i];
    reverse(c2.begin(), c2.end());
    for(int i = 0; i <s1.length(); i++) {
        if(c1[i] != c2[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}