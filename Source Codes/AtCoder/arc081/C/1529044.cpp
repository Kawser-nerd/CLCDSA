#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
#include <unordered_set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(int)(a);i--)
template<typename T> ostream& operator<<(ostream& s, vector<T> t) {rep(i, 0, t.size()) s << (i ? " " : "") << t[i]; return s;}
template<typename T> istream& operator>>(istream& s, vector<T> &t) {rep(i, 0, t.size()) s >> t[i]; return s;}
template<typename T, typename U> ostream& operator<<(ostream& s, pair<T, U> t) {s << "(" << t.first << "," << t.second << ")"; return s;}
template<typename T, typename U> istream& operator>>(istream& s, pair<T, U> &t) {s >> t.first >> t.second; return s;}
typedef long long ll;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main() {
    set<char> letters(alphabet.begin(), alphabet.end());

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> lens(n+1);
    lens[n] = 1;
    set<char> avail = letters;
    per(i,0,n) {
        lens[i] = lens[i+1];
        avail.erase(s[i]);
        if(avail.empty()) {
            lens[i]++;
            avail = letters;
        }
    }

    string res = "a";
    avail = letters;
    rep(i, 0, n) {
        avail.erase(s[i]);
        // cout << s[i] << " " << lens[i] << " " << res << endl;
        if(s[i] == res.back()) {
            if(res.size() + lens[i+1] <= lens[0]) {
                // cout << "y " << i << endl;
                res += "a";
                avail = letters;
                // for(auto x : avail) cout << x << " "; cout << endl;
            } else {
                assert(!avail.empty());
                res.back() = *avail.begin();
            }
        }
    }
    cout << res << endl;
}