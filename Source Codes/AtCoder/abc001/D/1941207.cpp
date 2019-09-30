#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;
using std::setfill;

using std::stoi;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    vector<int> e(n);
    for(int i = 0; i < n; i++){
        string l;
        cin >> l;

        s[i] = 60 * stoi(l.substr(0, 2)) + stoi(l.substr(2, 2));
        e[i] = 60 * stoi(l.substr(5, 2)) + stoi(l.substr(7, 2));
    }

    for(int i = 0; i < n; i++){
        s[i] = (s[i] / 5) * 5;
        e[i] = ((e[i] + 4) / 5) * 5;
    }

    vector<bool> r(25 * 60);
    for(int i = 0; i < n; i++){
        for(int j = s[i]; j <= e[i]; j++){
            r[j] = true;
        }
    }

    vector<int> rs;
    vector<int> re;
    for(int i = 0; i < 25 * 60; i++){
        if(!r[i]){
            continue;
        }
        rs.push_back(i);
        while(r[i]){
            i++;
        }
        i--;
        re.push_back(i);
    }

    int rnum = rs.size();
    for(int i = 0; i < rnum; i++){
        int s0 = rs[i] / 60;
        int s1 = rs[i] % 60;
        int e0 = re[i] / 60;
        int e1 = re[i] % 60;
        cout << setw(2) << setfill('0') << s0;
        cout << setw(2) << setfill('0') << s1;
        cout << "-";
        cout << setw(2) << setfill('0') << e0;
        cout << setw(2) << setfill('0') << e1;
        cout << endl;
    }



    return 0;
}