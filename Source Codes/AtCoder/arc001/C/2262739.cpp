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


int dp[1000];
int INF = 1000000;



int main(void){
	int A, B;
	cin >> A >> B;
	for (int i = 0; i < 1000; i++){
		dp[i] = INF;
	}
	dp[A] = 0;
	int remote[] = {1, 5, 10};
	for (int k = 0; k < 45; k++){
		for (int i = 0; i < 1000; i++){
			for (int j = 0; j < 3; j++){
				if (i - remote[j] >= 0 && dp[i - remote[j]] != INF){
					dp[i] = dp[i]>dp[i - remote[j]] + 1?dp[i - remote[j]] + 1:dp[i];
				}
				if (i + remote[j] < 1000 && dp[i + remote[j]] != INF){
					dp[i] = dp[i]>dp[i + remote[j]] + 1?dp[i + remote[j]] + 1:dp[i];
				}
			}
		}
	}

	cout << dp[B] << endl;
	return 0;
	
}