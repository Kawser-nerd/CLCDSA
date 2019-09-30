#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long int INF = 1000000007;

long long int pow_p(long long int num, long long int p){
	long long int pow_cur = num;
	long long int ret = 1;
	while(p > 0){
		if(p % 2 == 1){
			ret *= pow_cur;
			ret %= INF;
		}
		pow_cur *= pow_cur;
		pow_cur %= INF;
		p /= 2;
	}
	return ret;
}

int main(){
	
	string str;
	cin >> str;
	
	long long int ans = 0;
	
	for(int i = 0; i < str.size(); i++){
		if('0' <= str[i] && str[i] <= '9'){
			ans *= 10;
			ans += (str[i] - '0');
		}
	}
	
	cout << ans << endl;
	
	return 0;
}