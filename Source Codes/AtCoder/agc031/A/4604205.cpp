#include <iostream>
#include <vector>

#define DIV 1000000007

using namespace std;

int main() {
    int n;
    int a[26] = { 0 };
    vector<int> v;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (a[i] > 0) {
            v.push_back(a[i]);
        }
    }
    long result = 0;
    long prev = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        result = result + 1 + prev;
        if (result > DIV) {
            result = result % DIV;
        }
        for (int j = 1; j < *it; ++j) {
            result += 1 + prev;
            if (result > DIV) {
                result = result % DIV;
            }
        }
        prev = result;
    }
    cout << result << endl;    
}