/* 
 * in the name of god 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std; 

typedef long long LL; 
typedef pair<int,int> pii; 
typedef complex<double> point; 

int A,B,K;
long long dp[1000][2][2][2];

inline long long go (int pos, int fa, int fb, int fk){
	if (pos == -1){
		if (fa==false || fb == false || fk == false)
			return 0;
		return 1;
	}
	long long &ret = dp[pos][fa][fb][fk];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i=0; i<2; i++) if ((fa) || (i<=((A>>pos)&1)))
		for (int j=0; j<2; j++) if ((fb) || (j<=((B>>pos)&1))){
			int t = i & j;
			if ((fk) || (t<=((K>>pos)&1))){
				ret+= go(pos-1, fa || (i < ((A>>pos)&1)), fb || (j < ((B>>pos)&1)), fk || (t < ((K>>pos)&1)));	
			}
		}
	return ret;
}

inline void main2(){
	cin >> A >> B >> K;
	memset(dp, -1, sizeof dp);
	cout << go(30, 0, 0, 0) << endl;
}

int main(){
	int tt; cin >> tt;	
	for (int o=1; o<=tt; o++){
		cout << "Case #" << o << ": ";
		main2();
	}
	return 0;
}
