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

int x[105];
int y[105];

int main(void){
    int W, H, N;
    cin >> W >> H >> N;
    int sikaku[4] = {0, W, 0, H};
    for (int i = 0; i < N; i++){
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1){
            sikaku[0] = sikaku[0]<x?x:sikaku[0]; 
        }
        if (a == 2){
            sikaku[1] = sikaku[1]>x?x:sikaku[1];
        }
        if (a == 3){
            sikaku[2] = sikaku[2]<y?y:sikaku[2];
        }
        if (a == 4){
            sikaku[3] = sikaku[3]>y?y:sikaku[3];
        }
    }
    W = (sikaku[1]-sikaku[0]);
    H = (sikaku[3]-sikaku[2]);
    if (W >= 0 && H >= 0){
        cout << W*H << endl;
    }else{
        cout << 0 << endl;
    }

}