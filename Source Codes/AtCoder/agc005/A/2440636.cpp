#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    string s;
    cin >> s;

    stack<char> st;
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == 'S'){
            st.push(s[i]);
            continue;
        }

        if(st.empty() || st.top() == 'T'){
            st.push(s[i]);
            continue;
        }

        st.pop();
    }

    cout << st.size() << endl;

    return 0;
}