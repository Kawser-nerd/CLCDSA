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
		int n;
		cin>>n;
		int nimsum = 0;
		int smallest = 999999999;
		int total = 0;
		For(i,0,n){
			int a;cin>>a;
			smallest = min(a,smallest);
			total += a;
			nimsum ^= a;	
		}
		printf("Case #%d: ", tt);
		if(nimsum == 0)
			cout<<(total - smallest)<<endl;
		else
			cout<<"NO"<<endl;
	
	}
	

	return 0;
}
