#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

char table[501][501];
int main() {
	int H,W;
	cin >> H >> W;
	for(int i=0;i<H;i++){
		cin >> table[i];
	}
	for(int i=0;i<H;i++){
		cout << "#";
		for(int j=1;j<W-1;j++){
			if(i%2==0||table[i][j]=='#'){
				cout << "#";
			}
			else{
				cout << ".";
			}
		}
		cout << "." << endl;
	}
	cout << endl;
	for(int i=0;i<H;i++){
		cout << ".";
		for(int j=1;j<W-1;j++){
			if(i%2==1||table[i][j]=='#'){
				cout << "#";
			}
			else{
				cout << ".";
			}
		}
		cout << "#" << endl;
	}

	return 0;
}