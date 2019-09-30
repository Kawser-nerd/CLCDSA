#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;

int mp[100];

int nex (char x) {
    int y = x - 'a';
    for (int i = y; i < 26; i++)
        if (mp[i] == 0)
            return i;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
        mp[s[i] - 'a'] ++;

    if (n < 26) {
        cout << s;
        for (int i = 0; i < 26; i++)
            if (mp[i] == 0)
                return cout << char (i + 'a') << endl, 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (nex (s[i]) != -1) {
            for (int j = 0; j < i; j++)
                cout << s[j];
            cout << char (nex (s[i]) + 'a') << endl;
            return 0;
        }
        mp[s[i] - 'a'] --;
    }
    cout << -1 << endl;
}