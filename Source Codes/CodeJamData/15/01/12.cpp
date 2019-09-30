#include <iostream>
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>

#define REP(i,n) for(int i = 0; i<(n); i++)
#define ITER(i,v) for(auto i : v)
#define INF 1000000000
#define F(v) (v).begin(), (v).end()
#ifdef DEBUG
const bool DEBUG = true;
#else
const bool DEBUG = false;
#endif

using namespace std;

template <class T>
using priority_queue_asc =  priority_queue<T,vector<T>, greater<T> >;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int T;
	cin >> T;
	REP(i,T){
		int ans=0;
		int S;
		cin >> S;
		int sum=0;
		REP(j,S+1){
			char c; cin >> c; c -= '0';
			if(c>0 && sum < j){
				ans += j - sum;
				sum = j;
			}
			sum += c;
		}

		cout << "Case #"<<i+1<<": "<<ans<<"\n";
	}
	return 0;
}


