#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S;   cin >> S;
    string T;   cin >> T;

    vector<char> sv;
    vector<char> tv;

    for (auto c: S) sv.push_back(c);
    for (auto c: T) tv.push_back(c);
    
    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end(), greater<char>());

    string _S = "";
    string _T = "";

    for (auto c: sv) _S += c;
    for (auto c: tv) _T += c;

    if (_S < _T)    cout << "Yes" << endl;
    else            cout << "No" << endl;


    return 0;
}