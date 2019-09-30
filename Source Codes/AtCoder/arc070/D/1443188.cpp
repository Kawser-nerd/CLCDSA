#include<iostream>
#include<stack>
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	if(a<=b){cout<<"Impossible"<<endl;return 0;}
	stack<int> s;
	char c[10];
	int n=a+b;
	s.push(0);
	for(int i=1;i<n;i++)
		if(!s.empty())
		{
			int u=s.top();
			cout<<"? "<<u<<' '<<i<<endl;
			cin>>c;
			if(c[0]=='N')s.pop();
			else s.push(i);
		}
		else s.push(i);
	string ans;
	for(int i=0;i<n;i++)
	{
		cout<<"? "<<s.top()<<' '<<i<<endl;
		cin>>c;
		ans+=c[0]=='Y'?'1':'0';
	}
	cout<<"! "<<ans<<endl;
	return 0;
}