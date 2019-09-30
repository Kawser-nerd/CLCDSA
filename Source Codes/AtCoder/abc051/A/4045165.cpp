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

void solve(){

}
int main(){
    string s;
    cin >> s;

    string target = ",";
    string rep = " ";
    if (!target.empty()) {
        std::string::size_type pos = 0;
        while ((pos = s.find(target, pos)) != std::string::npos) {
            s.replace(pos, target.length(), rep);
            pos += rep.length();
        }
    }
    cout << s << endl;

    return 0;
}