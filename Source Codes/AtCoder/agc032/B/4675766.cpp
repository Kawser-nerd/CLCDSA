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

//?????
template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

//?????
template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

int a[105];
int cnt[105];
vector<int> ans;
vector<vector<int>> groups;
set<pair<int, int>> s;

int main(){
    cin.tie(0); 
    int N; cin >> N;


    int divisor = 0;
    for (int i = 2; i < N; i++){
        if ((N+N*N)/2 % i == 0){
            divisor = i;
            break;
        }
    }
    vector<int> tmp;
    for (int i = 1; i <= N/2; i++){
        tmp.clear();
        if (N % 2){
            tmp.push_back(i);
            tmp.push_back(N-i);
        }else{
            tmp.push_back(i);
            tmp.push_back(N+1-i);
        }
        groups.push_back(tmp);
    }
    tmp.clear();
    if (N % 2) tmp.push_back(N);
    groups.push_back(tmp);
    for (int i = 0; i < groups.size(); i++){
        for (int j = 0; j < groups[i].size(); j++){
            for (int k = i+1; k < groups.size(); k++){
                for (int l = 0; l < groups[k].size(); l++){
                    int a = groups[i][j];
                    int b = groups[k][l];
                    if (b < a) swap(b, a);
                    s.insert({a, b});
                }
            }
        }
    }
    cout << s.size() << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    return 0;
}