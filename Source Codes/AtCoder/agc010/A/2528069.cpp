#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include<iostream>

using namespace std;

typedef long long ll;

#define F first
#define S second

#define mp make_pair
#define pb push_back

#define pii pair<int,int>
#define pll pair<ll,ll>

const int N = 30000;
const int INF = int(2e9);
const int MOD = int(1e9) + 7;

string s;

int main()  
{
    freopen("debug.txt","w",stderr);

    int n,a[200100];
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i ++) {
    	cin >> a[i];
    	if(a[i] % 2 == 1) {
    		++ cnt;
    	}
    }
    if(cnt % 2 == 0) {
    	cout << "YES";
    }
    else {
    	cout << "NO";
    }
	return 0;  
}