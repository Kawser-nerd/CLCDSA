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
using namespace std;

long long a[100005];
long long bits[100];

int main(void){
    long long N, K; cin >> N >> K;
    for (int i = 0; i < N; i++){
        long long n; cin >> n;
        a[i] = n;
        int cnt = 0;
        while (n > 0){
            if (n % 2){
                bits[cnt]++;
            }
            n /= 2;
            cnt++;
        }
    }
    int limit = 0;
    while ((1LL<<(limit+1)) <= K){
        limit++;
    }
    long long X1 = 0;
    for (int i = 0; i < limit; i++){
        if (2*bits[i] < N){
            X1 += (1LL<<i);            
        }
    }
    long long X2 = (1LL<<limit);
    int flag = 0;
    for (int i = limit-1; i >= 0; i--){
        if (K & (1LL << i)){
            if (2*bits[i] >= N){
                flag = 1;
                continue;
            }else{
                X2 += (1LL << i);
            }
        }else{
            if (2*bits[i] < N && flag){
                X2 += (1LL << i);
            }
        }
    }
    long long ans = 0;
    long long ans2 = 0;
    if (!K){
        X1 = X2 = 0;
    }
    for (int i = 0; i < N; i++){
        ans += X1 ^ a[i];
    }
    for (int i = 0; i < N; i++){
        ans2 += X2 ^ a[i];
    }
    cout << (ans > ans2 ? ans : ans2) << endl;
    
    
}