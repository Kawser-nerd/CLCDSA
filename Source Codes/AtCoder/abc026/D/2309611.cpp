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

#define BIT(a) (1 << (a))

using namespace std;

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
    int A, B, C;
    cin >> A >> B >> C;

    double left = 0;
    double right = 300;
    double mid;
    for (int i = 0; i < 1000000; i++){
        double mid = (left + right)/2;
        if (A*mid+B*sin(C*mid*M_PI) < 100){
            left = mid;
        }else{
            right = mid;
        }
    }
    printf("%.14f\n", right);
    return 0;
}