#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    string s;
    cin >> s;
    auto string    = std::string(s);    // ????????
    auto separator = std::string("+");         // ?????
    auto separator_length = separator.length(); // ????????

    auto list = std::vector<std::string>();

    if (separator_length == 0) {
    list.push_back(string);
    } else {
        auto offset = std::string::size_type(0);
        while (1) {
            auto pos = string.find(separator, offset);
            if (pos == std::string::npos) {
            list.push_back(string.substr(offset));
            break;
            }
            list.push_back(string.substr(offset, pos - offset));
            offset = pos + separator_length;
        }
    }

    int ans = 0;
    for (auto t : list) {
        int sum = 0;
        for (int k = 0; k < (int)t.size(); k++) {
            //cout << t[k] << endl;
            if (t[k] == '0') {
                sum++;
            }
        }
        if (sum == 0) {
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}