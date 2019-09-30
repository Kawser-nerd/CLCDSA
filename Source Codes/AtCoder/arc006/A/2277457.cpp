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

int e[7];
int l[6];


int main(void){
	for (int i = 0; i < 7; i++){
		cin >> e[i];
	}
	set<int> s;
	for (int i = 0; i < 6; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < 6; i++){
		s.erase(e[i]);
	}
	switch (s.size()){
		case 0:
			cout << 1 << endl;
			break;
		case 1:
			s.erase(e[6]);
			if (s.size()) cout << 3 << endl;
			else cout << 2 << endl;
			break;
		default:
			if (s.size() + 2 < 6){
				cout << s.size() + 2 << endl;
			}else{
				cout << 0 << endl;
			}
	}
	
	return 0;
}