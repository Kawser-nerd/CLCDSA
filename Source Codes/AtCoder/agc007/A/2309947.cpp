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
//#include <boost/multiprecision/cpp_int.hpp>

#define BIT(a) (1 << (a))

using namespace std;
//using namespace boost::multiprecision;

long long MOD = 1000000007;


long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int main(void){
    int H, W;
    cin >> H >> W;
    int cnt = 0;
    char c;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            scanf(" %c", &c);
            if (c == '#') cnt++;
        }
    }
    if ((cnt - 1) == (H - 1) + (W - 1)){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
    
}