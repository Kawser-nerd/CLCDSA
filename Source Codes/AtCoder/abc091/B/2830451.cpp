#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    map<string, int> smap;
    vector<string> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;   cin >> s;
        if (smap.find(s) != smap.end()) smap[s]++;
        else {
            smap[s] = 1;
            v.push_back(s);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;   cin >> s;
        if (smap.find(s) != smap.end()) smap[s]--;
    }

    int ret = 0;
    for (auto e: v) {
        ret = max(smap[e], ret);
    }

    cout << ret << endl;

    return 0;
}