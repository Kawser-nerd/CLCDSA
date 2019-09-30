//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
long long mod = 1000000007;
long long dp[401][401];
long long cs[401][401];
int A[400], B[400];

int main(){
    int N,C;
    cin>>N>>C;
    for(int i= 0;i<N;i++) scanf("%d", &A[i]);
    for(int i= 0;i<N;i++) scanf("%d", &B[i]);
    for(int i=0;i<N;i++) {
        for(int j=A[i];j<B[i]+1;j++){
            long long p = 1;
            for(int k=0;k<C+1;k++) {
                cs[i][k]=(cs[i][k] + p) % mod;
                p=(p * j) % mod;
            }
        }
    }

    dp[0][0] = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=C;j++){
            for(int k=0;k<=j;k++) dp[i+1][j] = (dp[i+1][j] + dp[i][j-k] * cs[i][k]) % mod;
        }
    }
    cout<<dp[N][C]<<endl;
    return 0;
};