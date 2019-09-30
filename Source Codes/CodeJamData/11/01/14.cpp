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
#include <queue>
#include <stack>
#define For(i,a,b) for(int i=(a);i<(b);++i)

#define ForI(i,a,b) for(int i=(a);i<=(b);++i)
#define ForAll(it,set) for(typeof(set.begin()) it = set.begin(); it!=set.end(); ++it)

typedef stack<int> si;
typedef queue<int> qi;


int main(){
	int t;
	cin>>t;
	ForI(tt,1,t){
		int n;cin>>n;
		int pos[2]={1,1}, time[2] = {0,0};
		int curTime = 0;
		For(i,0,n){
			
			char type; int button;
			cin>>type>>button;
			type = (type=='B'?1:0);
			
			int nextTime = 1+max(curTime, time[type] + abs(button - pos[type]));
			pos[type] = button;
			time[type] = nextTime;
			curTime = nextTime;
		}
		cout<<"Case #"<<tt<<": "<<curTime<<endl;
	}
	
	

	return 0;
}
