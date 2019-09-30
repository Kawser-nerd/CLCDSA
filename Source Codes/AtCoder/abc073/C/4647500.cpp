#include <iostream>
#include <set>
using namespace std;
int main(){
	set<int>s;
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		if(s.find(k)==s.end())
			s.insert(k);
		else
			s.erase(k);
		
	}
	cout<<s.size()<<endl;
	return 0;
}