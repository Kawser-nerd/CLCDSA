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

int main(void){
	int N;
	cin >> N;
	vector<int> x(N), y(N);
	for (int i = 0; i < N; i++){
		cin >> x[i] >> y[i];
	}

	int max = -1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			int tmp = mod_pow(abs(x[i]-x[j]), 2) + mod_pow(abs(y[i]-y[j]), 2);
			max = max<tmp?tmp:max;
		}
	}

	printf("%f\n", sqrt(max));
	return 0;
}