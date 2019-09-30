#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>

#define REP(i,n) for(int i=0; i<n; i++)
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
 
#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9

using namespace std;
typedef long long ll;

int main(){
	bool furui[102];
	vector<int> primes;
	
	REP(i,102) furui[i] = true;
	furui[0] = false;
	furui[1] = false;
	for (int i=2; i<=102; i++){
		if (furui[i]){
			primes.push_back(i);
			for (int j=2; i*j<=102; j++){
				furui[i*j] = false;
			}
		}
	}
	
	const int len = primes.size();
	vector<int> countprimes(len);
	REP(i,len){
		countprimes[i] = 0;
	}
	
	int n, ans=0;
	
	cin >> n;
	
	for (int i=2; i<=n; i++){
		REP(j,len){
			if (i%primes[j]==0){
				for (int k=1; k<8; k++){
					if (i%(int)(pow(primes[j],k))==0){
						countprimes[j] += 1; 
					}
				}
			}
		}
	}
	
	REP(i,len){
		ans += (countprimes[i]>=74);
		REP(j,len){
			if (i==j){
				continue;
			}
			// 3*25
			ans += (countprimes[i]>=2) && (countprimes[j]>=24);
			// 5*15
			ans += (countprimes[i]>=4) && (countprimes[j]>=14);
			for (int k=j+1; k<len; k++){
				if (i==k || j==k){
					continue;
				}
				// 3*5*5
				ans += (countprimes[i]>=2) && (countprimes[j]>=4) && (countprimes[k]>=4);
			}
		}
	}
		
	cout << ans << endl;
	
	return 0;
}