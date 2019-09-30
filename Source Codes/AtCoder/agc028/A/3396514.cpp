#include <iostream>
#include <string>

constexpr int MAX_NM = 100000;

long long N, M;
std::string S, T;

long long gcd(long long a, long long b);

long long lcm(long long a, long long b);

int main(){

	std::cin >> N >> M >> S >> T;

	long long G = gcd(N, M);
	long long L = lcm(N, M);

	bool flag = true;

	for(int i = 0; i < G; ++i){
		if(S[i * (L / M)] != T[i * (L / N)]){
			flag = false;
			break;
		}
	}

	if(flag){
		std::cout << L << std::endl;
	}
	else{
		std::cout << -1 << std::endl;
	}

	return 0;
}

long long gcd(long long a, long long b){
	if(a == 0) return b;
	else return gcd(b % a, a);
}

long long lcm(long long a, long long b){
	return a * b / gcd(a, b);
}