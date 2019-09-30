#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <complex>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second

int main()
{
	li T;
	cin >> T;
	rep(loop, T){
		li n, p;
		cin >> n >> p; p--;
		
		li maxi, mini;
		{
			li low = 0, high = bit(n);
			while(low + 1 < high){
				li mid = (low + high) >> 1;
				li rem = mid;
				li pos = 0;
				rep(i, n){
					if(0 < rem){
						rem -= 1;
						rem /= 2;
						pos += bit(n - 1 - i);
					}
				}
				//cout << low << ", " << high << ", " << mid << ", " << pos << endl;
				if(p < pos) high = mid;
				else low = mid;
			}
			mini = low;
		}
		{
			li low = 0, high = bit(n);
			while(low + 1 < high){
				li mid = (low + high) >> 1;
				li rem = bit(n) - 1 - mid;
				li pos = 0;
				rep(i, n){
					if(0 < rem){
						rem -= 1;
						rem /= 2;
					}else{
						pos += bit(n - 1 - i);
					}
				}
				//cout << low << ", " << high << ", " << mid << ", " << pos << endl;
				if(pos <= p) low = mid;
				else high = mid;
			}
			maxi = low;
		}
		cout << "Case #" << loop + 1 << ": " << mini << " " << maxi << endl;
	}
}












