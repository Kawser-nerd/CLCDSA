#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<pair<string, string>> dic;

    for (int i = 0; i < N; i++) {
        string s, r;
        cin >> s;

        r = s;
        reverse(r.begin(), r.end());

        dic.emplace_back(make_pair(r, s));
    }

    sort(dic.begin(), dic.end());

    for (auto e:dic) {
        cout << e.second << endl;
    }
}