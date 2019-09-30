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

int ascii[300];
int ascii2[300];

int main(void){
	char s[30];
	cin >> s;
	int len = strlen(s);
	int start = 'a';
	int end = 'z';
	for (int i = 0; i < len; i++){
		ascii[s[i]] = 1;
	}
	for (int i = start; i <= end; i++){
		if (!ascii[i]){
			s[len] = (char)i;
			s[len+1] = '\0';
			printf("%s\n", s);
			return 0;
		}
	}
	
	for (int i = len-1; i >= 0; i--){
		if (i == len-1){
			ascii2[s[i]] = 1;
			continue;
		}
		for (int j = s[i]; j <= end; j++){
			if (ascii2[j]){
				s[i] = (char)j;
				s[i+1] = '\0';
				printf("%s\n", s);
				return 0;
			}else{
				ascii2[s[i]] = 1;
			}
		}
	}

	printf("-1\n");


	return 0;
}