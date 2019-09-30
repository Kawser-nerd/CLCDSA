#include<iostream>
#include<map>
#include<set>
using namespace std;
 
const int MAX_N=1e5+1;
 
set<int> s;
map<int,int> change;
int data[MAX_N];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
		s.insert(data[i]);
	}
	int tmp=0;
	for(set<int>::iterator itr=s.begin();itr!=s.end();itr++){
		change[*itr]=tmp++;
	}
	for(int i=0;i<n;i++){
		cout<<change[data[i]]<<endl;
	}
}