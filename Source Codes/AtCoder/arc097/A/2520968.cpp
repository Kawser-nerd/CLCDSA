#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

string s;
int K;

int main() {
    cin >> s;
    cin >> K;

    string s_ = s;
    sort(s_.begin(), s_.end());
    s_.erase(std::unique(s_.begin(), s_.end()), s_.end());

    set<string> substr;
    for (auto c : s_) {
        auto pos = s.find(c);
        while (pos != string::npos) {
            for (int i = 1; i <= min((int)(s.size() - pos), 5); ++i) {
                substr.insert(s.substr(pos, i));
            }
            pos = s.find(c, pos + 1);
        }
    }
    auto it = substr.begin();
    for (int i = 0; i < K - 1; ++i) ++it;
    cout << *it << endl;
}