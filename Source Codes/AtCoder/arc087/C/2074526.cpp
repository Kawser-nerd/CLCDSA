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
struct Trie {
    int lch = -1, rch = -1;
};
vector<Trie> trieTree;

ll L;

ll dfs(int v, int depth) {
    ll ret = 0;
    if (trieTree[v].lch == -1 && trieTree[v].rch == -1) {
        return 0;
    } else if (trieTree[v].lch != -1 && trieTree[v].rch != -1) {
        ret = dfs(trieTree[v].lch, depth + 1) ^ dfs(trieTree[v].rch, depth + 1);
    } else {
        ret = (L - depth) & -(L - depth);
        if (trieTree[v].lch == -1) {
            ret ^= dfs(trieTree[v].rch, depth + 1);
        } else {
            ret ^= dfs(trieTree[v].lch, depth + 1);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;

    cin >> N >> L;
    trieTree.push_back(Trie());
    rep(i, 0, N) {
        string s;
        cin >> s;
        int cur = 0;
        rep(j, 0, s.size()) {
            if (s[j] == '0') {
                if (trieTree[cur].lch == -1) {
                    trieTree[cur].lch = trieTree.size();
                    cur = trieTree.size();
                    trieTree.push_back(Trie());

                } else {
                    cur = trieTree[cur].lch;
                }

            } else {
                if (trieTree[cur].rch == -1) {
                    trieTree[cur].rch = trieTree.size();
                    cur = trieTree.size();
                    trieTree.push_back(Trie());
                } else {
                    cur = trieTree[cur].rch;
                }
            }
        }
    }

    if(dfs(0,0) == 0){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
    }

    return 0;
}