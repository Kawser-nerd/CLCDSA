#include <iostream>
using namespace std;
#include <cstdio>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
typedef pair<int,int> pii;
#include <vector>
typedef vector<int> vi;
typedef vector<int,int> vii;
#include <queue>
#include <stack>
#define For(i,a,b) for(int i=(a);i<(b);++i)
#define ForAll(it,set) for(typeof(set.begin()) it = set.begin(); it!=set.end(); ++it)
#define ForI(i,a,b) for(int i=(a);i<=(b);++i)

typedef set<int> si;
typedef map<int,int> mii;
typedef queue<int> qi;

int main(){

	int t;cin>>t;
	
	ForI(tt,1,t){
		int n;cin>>n;
		
		int loc[n+1];
		ForI(i,1,n)
			cin>>loc[i];
		int timeNeeded = 0;
		ForI(i,1,n)
			if(loc[i] != i)
				++timeNeeded;
		printf("Case #%d: %d.000000\n", tt,timeNeeded);
	
	
	}

	return 0;
}
