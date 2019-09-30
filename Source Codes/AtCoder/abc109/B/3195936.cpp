#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool doubleCheck(vector<string> words, string w) {
    bool ans = true;
    int cnt = 0;
    for (string s : words) {
        if (w == s) {
            cnt++;
        }
    }
    if (cnt != 1) {
        ans = false;
    }
    return ans;
}

bool checkWordStart(string beforeW, string w) {
    bool ans = true;

    if (*w.begin() != *--beforeW.end()) {
        ans = false;
    }

    return ans;
}
bool checkRule(vector<string> words, string w, int i) {
    bool ans = true;

    if (doubleCheck(words, w) != true || checkWordStart(words[i - 1], w) != true) {
        ans = false;
    }

    return ans;
}

int main()
{
    int n; cin >> n;
    vector<string> words;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        words.push_back(s);
    }

    for (int i = 1; i < n; i++) {
        if (checkRule(words, words[i], i) != true) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}