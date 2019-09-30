#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //?????(???????1???)
        x = (x * x) % MOD;
        n >>= 1; //????(n = n >> 1)
    }
    return res;
}

vector<vector<int>> edge(100005);
int v[100005];
vector<int> ans;
int flag;

int dfs(int crt){
    ans.push_back(crt);
    v[crt] = 1;
    for (auto i : edge[crt]){
        if (!v[i] && !flag){
            dfs(i);
        }
    }
    if (!flag) flag = 1;

    return 0;
}

int dfs2(int crt){
    v[crt] = 1;
    for (auto i : edge[crt]){
        if (v[i] == 0){
            ans.push_back(i);
            dfs2(i);
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    exit(0);

    return 0;
}


int main(){
    cin.tie(0);

    Int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1);
    reverse(ans.begin(), ans.end());
    dfs2(1);
    
}