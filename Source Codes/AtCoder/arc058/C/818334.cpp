#include <iostream>

using namespace std;

#define DP_LEN (1<<(5+7+5))
#define MOD 1000000007



typedef long long ll;

int n,x,y,z;
int mask,mask2,target;

int dpA[DP_LEN];
int dpB[DP_LEN];
int *dp1 = dpA, *dp2 = dpB;
int ans = 0;

int main(){
	cin >> n >> x >> y >> z;
	mask = (1<<(x+y+z))-1;
	mask2 = mask>>1;
	
	target   = 1;
	target <<= x-1;
	
	target <<= 1;
	target  += 1;
	target <<= y-1;
	
	target <<= 1;
	target  += 1;
	target <<= z-1;
	
	dp1[0] = 1;
	for(int i = 0;i < n;i++){
		swap(dp1, dp2);
		for(int k = 0;k <= mask2;k++){
			dp1[k] = 0;
		}
		
		ans = (((ll)ans) * 10ll) % MOD;
		for(int a = 1;a <= 10;a++){
			for(int k = 0;k <= mask2;k++){
				int kk = k;
				kk <<= 1;
				kk  += 1;
				kk <<= a-1;
				if((kk & target) == target){
					ans += dp2[k];
					ans %= MOD;
				}else{
					dp1[kk & mask2] += dp2[k];
					dp1[kk & mask2] %= MOD;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}