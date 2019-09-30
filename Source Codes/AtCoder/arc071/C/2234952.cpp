#include <iostream>
#include <string>

constexpr int MAX = 100000;

std::string S, T;
int q;

int main(){

	std::cin >> S >> T >> q;
	
	int scsum[MAX + 1] = {}, tcsum[MAX + 1] = {};
	for(int i = 0; i < S.length(); ++i){
		if(S[i] == 'A'){
			scsum[i + 1] = 1 + scsum[i];
		}
		else{
			scsum[i + 1] = 2 + scsum[i];
		}
	}
	for(int i = 0; i < T.length(); ++i){
		if(T[i] == 'A'){
			tcsum[i + 1] = 1 + tcsum[i];
		}
		else{
			tcsum[i + 1] = 2 + tcsum[i];
		}
	}
	for(int i = 0; i < q; ++i){
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		if((scsum[b] - scsum[a - 1]) % 3 == (tcsum[d] - tcsum[c - 1]) % 3){
			std::cout << "YES" << std::endl;
		}
		else{
			std::cout << "NO" << std::endl;
		}
	}

	return 0;
}