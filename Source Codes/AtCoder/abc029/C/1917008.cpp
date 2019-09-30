#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;

void backtrack(int n, int d, string& s, vector<string>& ans) {
    if(d >= n){
        ans.push_back(s);
        return;
    }

    for(char c = 'a'; c <= 'c'; c++){
        s.push_back(c);
        backtrack(n, d + 1, s, ans);
        s.pop_back();
    }

    return;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans;
    string s;
    backtrack(n, 0, s, ans);

    sort(ans.begin(), ans.end());

    for (const string& s : ans) {
        cout << s << endl;
    }

    return 0;
}