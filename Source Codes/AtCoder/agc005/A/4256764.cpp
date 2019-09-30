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
#include <set>
#include <stack>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    string s;
    cin >> s;

    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') {
            st.push(s[i]);
        } else if (s[i] == 'T' &&  st.size() == 0) {
            st.push(s[i]);
        } else if (s[i] == 'T' && st.top() == 'T') {
            st.push(s[i]);
        } else if (s[i] == 'T' && st.top() == 'S') {
            st.pop();
        }
    }

    cout << st.size() << endl;





    return 0;
}