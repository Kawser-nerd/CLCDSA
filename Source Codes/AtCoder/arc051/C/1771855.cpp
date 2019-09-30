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
	
	long long int N, A, B;
	cin >> N >> A >> B;
	
	long long int a[100];
	
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	if(A == 1){
		sort(a, a + N);
		for(int i = 0; i < N; i++){
			cout << a[i] << endl;
		}
		return 0;
	}
	
	while(true){
		sort(a, a + N);
		if(B == 0){
			break;
		}
		if(a[0] * A > a[N - 1]){
			break;
		}
		a[0] *= A;
		B--;
	}
	
	long long int p = B / N;
	B = B % N;
	
	for(int i = 0; i < N; i++){
		a[i] = (a[i] * pow_p(A, p)) % INF;
	}
	
	for(int i = 0; i < N - B; i++){
		cout << a[B + i] << endl;
	}
	
	for(int i = N - B; i < N; i++){
		cout << (a[i - N + B] * A) % INF << endl;
	}
	
	return 0;
}