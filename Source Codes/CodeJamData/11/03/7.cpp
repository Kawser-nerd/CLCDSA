#include <iostream>
using namespace std;
int main(){
	int tnum;cin>>tnum;
	int tcou=0;
	while (tnum--){
		int n;cin>>n;
		int m=-1;
		int x=0;
		int s=0;
		while (n--){
			int a;cin>>a;
			x^=a;
			if (m==-1 || a<m)
				m=a;
			s+=a;
		}
		cout<<"Case #"<<++tcou<<": ";
		if (x!=0)
			cout<<"NO"<<endl;
		else
			cout<<s-m<<endl;
	}
	return 0;
}
