#include <iostream>
using namespace std;

int main() {
int n,x=0;

cin>>n;
char s[n];
cin>>s;
int max=x;
for(int i=0;i<n;i++)
{
	if(s[i]=='I')
	{
		++x;
		if(x>max)
		max=x;
	}
	if(s[i]=='D')
	{
		--x;
		
	}
	
}
cout<<max;


}