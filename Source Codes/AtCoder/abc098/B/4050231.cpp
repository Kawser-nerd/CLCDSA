#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        string l = S.substr(0, i);
        string r = S.substr(i);

        set<char> ls;
        for (char c : l) {
            ls.insert(c);
        }
        set<char> rs;
        for (char c : r) {
            rs.insert(c);
        }
        set<char> tmp;
        set_intersection(
            ls.begin(), ls.end(), rs.begin(), rs.end(),
            inserter(tmp, tmp.end()));
        ans = max(ans, (int)tmp.size());
    }
    cout << ans << endl;
}