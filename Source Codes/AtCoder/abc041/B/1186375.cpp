#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    ll A, B, C;
    cin>>A>>B>>C;
    ll MOD = pow(10, 9) + 7;
    ll ans;
    ans = A * B % MOD;
    ans *= C % MOD;
    cout << ans % MOD << endl;
}