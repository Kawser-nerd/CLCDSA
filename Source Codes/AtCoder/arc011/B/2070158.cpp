#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string keys = "zrbcdwtjfqlvsxpmhkng";
    map<char, int> mp;
    rep(i, 0, 20) {
        mp[keys[i]] = i / 2;
    }
    int N;
    cin >> N;
    vector<string> anss;
    rep(i, 0, N) {
        string s;
        cin >> s;
        rep(j, 0, s.size()) {
            if (s[j] - 'A' >= 0 && s[j] - 'A' < 26) {
                s[j] = s[j] + 'a' - 'A';
            }
        }
        string ans;
        rep(j, 0, s.size()) {
            if (mp.find(s[j]) != mp.end())
                ans += (char) ('0' + mp[s[j]]);
        }
//        cout << ans;
//        cout << (i == N - 1) ? "\n" : " ";
//        if (i == N - 1) cout << endl;
//        else if(ans.size()) cout << " ";
        if(ans.size()) anss.push_back(ans);
    }
    rep(i, 0, anss.size()) {
        cout << anss[i];
        if (i == anss.size() - 1) cout << endl;
        else cout << " ";
    }
    if(!anss.size()) cout << endl;


    return 0;
}