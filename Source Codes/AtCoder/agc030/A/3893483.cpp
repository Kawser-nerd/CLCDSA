#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
const int N=100005,M=1000005,mod=1000000007;
const long long llinf=9223372036854775807ll;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	if(b>=c)
		cout<<b+c;
	else
	{
		if((a+b)>=c)
			cout<<b+c;
		else
			cout<<a+b+b+1;
	}
	return 0;
}