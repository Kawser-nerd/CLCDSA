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

int d[105][105];
int edge[105][105];

int main(){
    cin.tie(0);

    int N, M; cin >> N >> M;
    int INF = 1000000000;
    fill(d[0], d[105], INF);
    fill(edge[0], edge[105], INF);
    for (int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
        edge[a][b] = c;
        edge[b][a] = c;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            for (int k = 1; k <= N; k++){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (edge[i][j] != INF){
                if (edge[i][j] > d[i][j]) ans++;
            }
        }
    }
    cout << ans/2 << endl;
} ./Main.cpp:50:16: warning: array index 105 is past the end of the array (which contains 105 elements) [-Warray-bounds]
    fill(d[0], d[105], INF);
               ^ ~~~
./Main.cpp:42:1: note: array 'd' declared here
int d[105][105];
^
./Main.cpp:51:19: warning: array index 105 is past the end of the array (which contains 105 elements) [-Warray-bounds]
    fill(edge[0], edge[105], INF);
                  ^    ~~~
./Main.cpp:43:1: note: array 'edge' declared here
int edge[105][105];
^
2 warnings generated.