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
#define bit(a) (1<<(a-'a'))
int main(){
	int t;cin>>t;
	
	
	ForI(tt,1,t){
		int c;
		cin>>c;
		mii combinations;
		string s;
		For(i,0,c){
			cin>>s;
			combinations[bit(s[0])|bit(s[1])] =  s[2];		
		}
		int d;
		cin>>d;
		vi opposed(d);
		For(i,0,d){
			cin>>s;
			opposed[i] = bit(s[0]) | bit( s[1]);
				
		}
		int n;cin>>n;
		string elements;
		
		string invoked;
		cin>>invoked;
		For(i,0,n){
			elements += invoked[i];
			while(elements.size() >= 2){
				int lastTwo = bit(elements[elements.size() - 1]) | bit(elements[elements.size() - 2]);
				if(combinations[lastTwo] == 0)break;
				elements.resize(elements.size() - 2);
				elements+= combinations[lastTwo];			
			}
			int elementSet = 0;
			ForAll(it,elements)
				elementSet |= bit(*it);
			ForAll(it, opposed)
				if((*it&elementSet) == *it){
					elementSet = 0;
					elements.clear();
				}
					
		
		}
		cout<<"Case #"<<tt<<": "<<"[";
		For(i,0,elements.size()){
			if(i > 0)cout<<", ";
			cout<<elements[i];
		}
		cout<<"]"<<endl;
				
		
	}
	

	return 0;
}
