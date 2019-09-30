#include<iostream>
#include<cstring>
using namespace std;
string s;
int f[200000];
bool check(int x)
{
	if(f[x]!=-1)return f[x];
	if(x==s.size())return 1;
	if(s.size()-x>6&&s.substr(x,7)=="dreamer"&&check(x+7))return f[x]=1;
	if(s.size()-x>5&&s.substr(x,6)=="eraser"&&check(x+6))return f[x]=1;
	if(s.size()-x>4&&s.substr(x,5)=="dream"&&check(x+5))return f[x]=1;
	if(s.size()-x>4&&s.substr(x,5)=="erase"&&check(x+5))return f[x]=1;
	return f[x]=0;
}
int main()
{
	cin>>s;
	memset(f,-1,sizeof f);
	cout<<(check(0)?"YES":"NO")<<endl;
	return 0;
}