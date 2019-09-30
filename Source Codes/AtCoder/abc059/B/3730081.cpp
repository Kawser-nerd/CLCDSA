#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;
const double PI = acos(-1);
const int maxn = 105;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string A,B, ans;
	cin >> A;
	cin >> B;
	int lenA = A.length();
	int lenB = B.length();
	if(lenA > lenB) ans = "GREATER";
	else if(lenA < lenB) ans = "LESS";
	else{
		for(int i = 0; i < lenA; i++){
			if(A[i] > B[i]){ ans = "GREATER"; break;}
			else if(A[i] < B[i]){ ans = "LESS"; break;}
			else if(A[lenA - 1] == B[lenB - 1]){ ans = "EQUAL";}
		}
	}
	cout << ans << endl;
	return 0 ;
}