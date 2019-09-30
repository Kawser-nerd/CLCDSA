#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    vector<string> table;
    table.push_back("dream");
    table.push_back("dreamer");
    table.push_back("erase");
    table.push_back("eraser");

    for(int i = 0; i < table.size(); ++i) {
        reverse(table[i].begin(), table[i].end());
    }

    int i = 0;
    for(; i < s.size();) {
        bool ok = false;
        for(int j = 0; j < 4; ++j) {
            if (table[j] == s.substr(i, table[j].size())) {
                ok = true;
                i += table[j].size();
                break;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (i == s.size()) {
        cout << "YES" << endl;
    } else {
        cerr << s.size() << endl;
        cerr << i << endl;
        cout << "NO" << endl;
    }
    return 0;
}