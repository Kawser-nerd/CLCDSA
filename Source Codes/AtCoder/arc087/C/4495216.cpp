#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

struct node{
    int d, l, r;
    node(int d) : d(d) {
        l = r = -1;
    }
};

vector<node> trie;

void add(string s, int id){
    while(SZ(s) > trie[id].d){
        if(s[trie[id].d] == '0'){
            if(trie[id].l == -1){
                trie[id].l = SZ(trie);
                trie.push_back(node(trie[id].d + 1));
            }
            id = trie[id].l;
        }else{
            if(trie[id].r == -1){
                trie[id].r = SZ(trie);
                trie.push_back(node(trie[id].d + 1));
            }
            id = trie[id].r;
        }
    }
}

int grundy(int h){
    if(h == 0){
        return 0;
    }

    int x = 1;
    while(h % (x * 2) == 0){
        x *= 2;
    }
    return x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    trie.push_back(node(0));
    rep(i, n){
        string s;
        cin >> s;
        add(s, 0);
    }

    int sum = 0;
    stack<int> st;
    st.push(0);
    while(not st.empty()){
        int id = st.top();
        st.pop();

        if(trie[id].l == -1 && trie[id].r == -1){
            continue;
        }

        if(trie[id].l != -1){
            st.push(trie[id].l);
        }else{
            int h = l - trie[id].d;
            sum ^= grundy(h);
        }
        if(trie[id].r != -1){
            st.push(trie[id].r);
        }else{
            int h = l - trie[id].d;
            sum ^= grundy(h);
        }
    }

    cout << (sum == 0 ? "Bob" : "Alice") << endl;

    return 0;
}