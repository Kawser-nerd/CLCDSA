#include <iostream>
#include <fstream>
#include <string> 
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

#include <boost/multiprecision/cpp_int.hpp>

#define BIT(a) (1 << (a))

using namespace std;
using namespace boost::multiprecision;

long long MOD = 1000000007;


long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int edge[100005];
int cost[100005];

int main(void){
    int N, a;
    cin >> N >> a;
    cpp_int k;
    cin >> k;
    for (int i = 1; i <= N; i++){
        cin >> edge[i];
        cost[i] = -1;
    }

    int cnt = 0;
    int next = a;
    while (cost[next] == -1){
        cost[next] = cnt;
        if (cost[next] == k){
            cout << next << endl;
            return 0;
        }
        cnt++;
        next = edge[next];
    }
    int search = cost[next] + (int)((k-cost[next]) % (cnt - cost[next]));
    for (int i = 1; i <= N; i++){
        if (cost[i] == search){
            cout << i << endl;
        }
    }
    return 0;
}