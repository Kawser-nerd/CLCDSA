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

Int X[100005];
Int W[100005];
vector<Int> moved;
Int ans[100005];

int main(){
    cin.tie(0);

    Int N, L, T; cin >> N >> L >> T;
    for (int i = 0; i < N; i++){
        cin >> X[i] >> W[i];
    }

    for (int i = 0; i < N; i++){
        Int pos = X[i];
        if (W[i] == 1) pos += T;
        else pos -= T;

        if (pos < 0) pos = L + (pos%L);
        else pos %= L;
        if (pos == L) pos = 0;

        moved.push_back(pos);
    }

    Int first;
    Int first_pos;
    Int cnt = 0;
    for (int i = 0; i < N; i++){
        if (W[i] == 1){
            for (int j = i+1; j < i+N; j++){
                if (W[j%N] == 2){
                    Int a, b;
                    if(X[i] > X[j]) b = -X[j];
                    else b = L-X[j];
                    a = X[i] + T;
                    b += T;
                    cnt += (a+b)/L;
                }
            }
            first = (i+cnt)%N;
            first_pos = (X[i]+T)%L;
            break;
        }
        if (i == N-1){
            for (int j = 0; j < N; j++){
                cout << moved[j] << endl;
            }
            return 0;
        }
    }
    sort(moved.begin(), moved.end());
    for (int i = moved.size()-1; i >= 0; i--){
        if (moved[i] == first_pos){
            for (int j = 0; j < N; j++){
                ans[(first+j)%N] = moved[(i+j)%N];
            }
            break;
        }
    }
    for (int i = 0; i < N; i++) cout << ans[i] << endl;
}