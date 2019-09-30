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
//#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
//#define EXIST(s, e) ((s).find(e)!=(s).end())
//#define SORT(c) sort(begin(c),end(c))
//#define pb emplace_back
//#define MP make_pair
//#define SZ(a) int((a).size())

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
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????
vector<pair<int, vector<int>>> tree;//??0,??1
vector<pair<int, vector<int>>> tree1;//??0,??1
vector<bool> traveled;
set<int> rests;//?????

//??????????????
bool del(int key) {
    if (traveled[key]) return true;
    traveled[key] = true;

    int sz = 0;
    for (int i = 0; i < tree[key].second.size(); i++) {
        int to = tree[key].second[i];
        if (!traveled[to]) sz++;
    }
    if (sz == 0) {
        if (tree[key].first == 1) return true;
        rests.insert(key);
        return false;
    }

    bool ret = true;
    for (int i = 0; i < tree[key].second.size(); i++) {
        if (!del(tree[key].second[i])) {
            ret = false;
        }
    }
    if (tree[key].first == 0) ret = false;

    if (!ret) {
        rests.insert(key);
    }

    return ret;
}

//????????????????
//restruct(???????)
void restruct(int key) {
    if (traveled[key]) return;
    traveled[key] = true;

    if (rests.find(key) != rests.end()) {
        tree1[key].first = tree[key].first;
        for (int i = 0; i < tree[key].second.size(); i++) {
            int to = tree[key].second[i];
            if (rests.find(to) != rests.end() && !traveled[to]) {
                tree1[key].second.push_back(to);
                tree1[to].second.push_back(key);
                restruct(to);
            }
        }
    }

}

//first key, second value
pair<int, int> max_black(int key) {
    pair<int, int> ret(-1, 0);
    traveled[key] = true;

    int sz = 0;
    for (int i = 0; i < tree1[key].second.size(); i++) {
        int to = tree1[key].second[i];
        if (!traveled[to]) sz++;
    }
    if (sz == 0) {
//        ret.second = 1;
        if (tree1[key].first == 0) {
            ret.first = key;
            ret.second = 1;
        } else {
            ret.first = key;
            ret.second = 0;
        }
        return ret;
    }
    for (auto to : tree1[key].second) {
        if (traveled[to]) continue;
        auto tmp = max_black(to);
        if (tree1[key].first == 0) {
//            ret.first = tmp.first;
//            ret.second = 1 + tmp.second;
            tmp.second++;
        } else {
//            ret.first = tmp.first;
//            ret.second = tmp.second;
        }
        if(tmp.second >= ret.second) ret = tmp;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    tree.resize(N);
    tree1.resize(N);
    traveled.resize(N, false);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        tree[x].second.push_back(y);
        tree[y].second.push_back(x);
    }

    string c;
    cin >> c;
    for (int i = 0; i < N; i++) {
        if (c[i] == 'W') {
            tree[i].first = 0;
        } else {
            tree[i].first = 1;
        }
    }


//    traveled.fill(false);
//    fill(traveled.begin(),traveled.end(),false);
    fill(all(traveled), false);
//    del(0);
    if(true){
        int key = -1;
        for (int i = 0; i < N; i++) {
            if (tree[i].first == 0) {
                key = i;
                break;
            }
        }
        if(key == -1){
            cout << 0 << endl;
            return 0;
        }
        del(key);
    }
    fill(all(traveled), false);
    {
        int key = 0;
        for (int i = 0; i < N; i++) {
            if (tree[i].first == 0) {
                key = i;
                break;
            }
        }
        restruct(key);
    }

    if (rests.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    if(rests.size() == 1){
        cout << 1 << endl;
        return 0;
    }

    int score = rests.size() * 2 - 2;
//    for (auto e : rests) {
//        cout << e + 1 << endl;
//    }

//    cout << "bef" << endl;
//    for(int i = 0; i < N; i++){
//        cout << tree1[i].second.size() << endl;
//    }
//    for(int i = 0; i < N; i++){
//        cout << tree1[i].first << endl;
//    }
//    for (int i = 0; i < N; i++) {
//        tree1[i].first ^= tree1[i].second.size() % 2;
//        score += tree1[i].first == 0;
//    }
    for(auto e : rests){
        tree1[e].first ^= tree1[e].second.size() % 2;
        score += tree1[e].first == 0;
    }

//    cout << "aft" << endl;
//    for(int i = 0; i < N; i++){
//        cout << tree1[i].first << endl;
//    }

    if (true) {
        fill(all(traveled), false);
        auto tmp = max_black(*rests.begin());
        fill(all(traveled), false);
        tmp = max_black(tmp.first);
        score -= 2 * tmp.second;
    }
    cout << score << endl;

//    if(true){
//        for(auto e : rests){
//            cout << e + 1 << " " << tree1[e].second.size() << endl;
//        }
//    }


    return 0;
}