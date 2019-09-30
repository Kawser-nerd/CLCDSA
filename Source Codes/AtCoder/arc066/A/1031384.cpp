#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

ll modPow(ll base, ll ex, ll m) {
	ll ret = 1;
	while(ex){
		if(ex & 1){
			ret = ret * base % m;
		}
		ex >>= 1;
		base = base * base % m;
	}
	return ret;
}

int main(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        mp[a]++;
    }
    bool zero = false;
    if(n % 2 == 0){
        for(int i=1;i<n;i+=2){
            if(mp[i] != 2){
                zero = true;
                break;
            }
        }
    }else{
        if(mp[0] != 1){
            zero = true;
        }
        for(int i=2;i<n;i+=2){
            if(mp[i] != 2){
                zero = true;
                break;
            }
        }
    }
    cout << (zero ? 0 : modPow(2, n / 2, M)) << '\n';
    return 0;
}