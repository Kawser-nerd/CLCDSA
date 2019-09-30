#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <random>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <sstream>
#define REP(i,x) for(int i=0; i<(x); i++)
typedef long long ll;
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    string n;
	cin >> n;
	int dig[16];
	int ma = 0;
	REP(i,n.length()){
		dig[i] = n[i] - '0';
		ma += dig[i];
	}
	int kouho = dig[0]-1+(9*(n.length()-1));
	ma = max(ma,kouho);
	
	cout << ma << endl;
    
    return 0;
}