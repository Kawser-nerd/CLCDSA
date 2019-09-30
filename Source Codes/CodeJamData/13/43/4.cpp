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


#define MAX 2050
li a[MAX];
li b[MAX];
li used[MAX];
li ans[MAX];
set<li> lower[MAX];

int main()
{
	li T;
	cin >> T;
	
	rep(loop, T){
		li n;
		cin >> n;
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		rep(i, MAX) lower[i].clear();
		
		rep(i, n){
			for(li j = i - 1; 0 <= j; j--)if(a[i] == a[j]){
				lower[j].insert(i);
				break;
			}
			for(li j = i - 1; 0 <= j; j--)if(a[i] == a[j] + 1){
				lower[i].insert(j);
				break;
			}
		}
		rep(i, n){
			for(li j = i + 1; j < n; j++)if(b[i] == b[j]){
				lower[j].insert(i);
				break;
			}
			for(li j = i + 1; j < n; j++)if(b[i] == b[j] + 1){
				lower[i].insert(j);
				break;
			}
		}
		
		memset(ans, -1, sizeof(ans));
		for(li mini = 1; mini <= n; mini++){
			rep(j, n)if(ans[j] == -1 && sz(lower[j]) == 0){
				ans[j] = mini;
				rep(k, n) lower[k].erase(j);
				break;
			}
		}
		cout << "Case #" << loop + 1 << ": ";
		rep(i, n) cout << ans[i] << (i + 1 != n ? " " : ""); cout << endl;
		
	}

}












