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

class BinaryTrie{
    struct node{
        int d, l, r;
        node(int d) : d(d) {
            l = r = -1;
        }
    };

    public:
        vector<node> nodes;

        BinaryTrie(){
            nodes.push_back(node(0));
        }

        void add(string& s, int id){
            while(SZ(s) > nodes[id].d){
                if(s[nodes[id].d] == '0'){
                    if(nodes[id].l == -1){
                        nodes[id].l = SZ(nodes);
                        nodes.push_back(node(nodes[id].d + 1));
                    }
                    id = nodes[id].l;
                }else{
                    if(nodes[id].r == -1){
                        nodes[id].r = SZ(nodes);
                        nodes.push_back(node(nodes[id].d + 1));
                    }
                    id = nodes[id].r;
                }
            }
        }
};

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

    BinaryTrie trie;
    rep(i, n){
        string s;
        cin >> s;
        trie.add(s, 0);
    }

    int sum = 0;
    stack<int> st;
    st.push(0);
    while(not st.empty()){
        int id = st.top();
        st.pop();

        if(trie.nodes[id].l == -1 && trie.nodes[id].r == -1){
            continue;
        }

        if(trie.nodes[id].l != -1){
            st.push(trie.nodes[id].l);
        }else{
            int h = l - trie.nodes[id].d;
            sum ^= grundy(h);
        }
        if(trie.nodes[id].r != -1){
            st.push(trie.nodes[id].r);
        }else{
            int h = l - trie.nodes[id].d;
            sum ^= grundy(h);
        }
    }

    cout << (sum == 0 ? "Bob" : "Alice") << endl;


    return 0;
}