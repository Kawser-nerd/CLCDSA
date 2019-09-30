#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	long long L,P,C,ji,now,ans,test,numtest;
	
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> numtest;
	for(test=1;test<=numtest;test++)
	{
		cin >> L >> P >> C;
		ji=0;
		while(L<P){L*=C;ji++;};
		now=1;
		ans=0;
		while(now<ji){now*=2;ans++;};
		cout<<"Case #"<<test<<": "<<ans<<endl;
	}
	return 0;
}
